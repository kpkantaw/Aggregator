//
//  Aggregator.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//  Contains functions related to reading the feed data. 
//  Once parsing has been initiated, the delegate will receive the feed data as it is parsed.

#import <Foundation/Foundation.h>
#import "FeedInfo.h"
#import "FeedItem.h"

// Debug Logging
#if 0 // Set to 1 to enable debug logging
#define MyLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define MyLog(x, ...)
#endif

// Errors & codes
#define MyErrorDomain @"MyAggregator"
#define MyErrorCodeNotInitiated				1		/* MyAggregator not initialised correctly */
#define MyErrorCodeConnectionFailed			2		/* Connection to the URL failed */
#define MyErrorCodeFeedParsingError			3		/* NSXMLParser encountered a parsing error */
#define MyErrorCodeFeedValidationError		4		/* NSXMLParser encountered a validation error */
#define MyErrorCodeGeneral					5		/* MyAggregator general error */

// Class
@class MyAggregator;

// Types
typedef enum { ConnectionTypeAsynchronously, ConnectionTypeSynchronously } ConnectionType;
typedef enum { ParseTypeFull, ParseTypeItemsOnly, ParseTypeInfoOnly } ParseType;
typedef enum { FeedTypeUnknown, FeedTypeRSS, FeedTypeRSS1, FeedTypeAtom } FeedType;

// Delegate
@protocol MyAggregatorDelegate <NSObject>
@optional

//Once parsing has been initiated, the delegate will receive the feed data as it is parsed.
// aggregatorDidStart:: Called when data has downloaded and parsing has begun
- (void)aggregatorDidStart:(MyAggregator *)parser;

//aggregator..info:: Provides info about the feed
- (void)aggregator:(MyAggregator *)parser didParseFeedInfo:(MyFeedInfo *)info;

//aggregator..item:: Provides info about a feed item
- (void)aggregator:(MyAggregator *)parser didParseFeedItem:(MyFeedItem *)item;

/* aggregatorDidFinish:: Parsing complete or stopped at any time by `stopParsing`
   This function will only be called when the feed has successfully parsed, or has been stopped by a call to stopParsing */

- (void)aggregatorDidFinish:(MyAggregator *)parser;

//didFailWithError:: Parsing failed
- (void)aggregator:(MyAggregator *)parser didFailWithError:(NSError *)error;

@end

// MyAggregator
@interface MyAggregator : NSObject <NSXMLParserDelegate> {
	
@private
	
	// Required
	id <MyAggregatorDelegate> delegate;
	NSString *url;
	
	// Connection
	NSURLConnection *urlConnection;
	NSMutableData *asyncData;
	ConnectionType connectionType;
	
	// Parsing
	ParseType feedParseType;
	NSXMLParser *aggregator;
	FeedType feedType;
	NSDateFormatter *dateFormatterRFC822, *dateFormatterRFC3339;
	BOOL parsing; // Whether the MyAggregator has started parsing
	BOOL hasEncounteredItems; // Whether the parser has started parsing items
	BOOL aborted; // Whether parse stopped due to abort
	BOOL stopped; // Whether the parse was stopped
	BOOL failed; // Whether the parse failed
	BOOL parsingComplete; // Whether NSXMLParser parsing has completed
	
	// Parsing of XML structure as content
	NSString *pathOfElementWithXHTMLType; // Hold the path of the element who's type="xhtml" so we can stop parsing when it's ended
	BOOL parseStructureAsContent; // For atom feeds when element type="xhtml"
	
	// Parsing Data
	NSString *currentPath;
	NSMutableString *currentText;
	NSDictionary *currentElementAttributes;
	MyFeedItem *item;
	MyFeedInfo *info;
	
}

#pragma mark Public Properties

// Delegate to recieve data as it is parsed
@property (nonatomic, assign) id <MyAggregatorDelegate> delegate;

// Whether to parse feed info & all items, just feed info, or just feed items
@property (nonatomic) ParseType feedParseType;

// Set whether to download asynchronously or synchronously
@property (nonatomic) ConnectionType connectionType;

// Whether parsing was stopped
@property (nonatomic, readonly, getter=isStopped) BOOL stopped;

// Whether parsing failed
@property (nonatomic, readonly, getter=didFail) BOOL failed;

// Whether parsing is in progress
@property (nonatomic, readonly, getter=isParsing) BOOL parsing;

#pragma mark Public Methods

// Init MyAggregator with a URL string, 
// Create feed parser and pass the URL of the feed in individual view controllers.
- (id)initWithFeedURL:(NSString *)feedURL;

// Begin parsing
- (BOOL)parse;

// Stop parsing
- (void)stopParsing;

// Returns the URL
- (NSString *)url;

@end