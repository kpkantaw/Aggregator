//
//  Aggregator_P.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

@interface MyAggregator ()

#pragma mark Private Properties

// Feed Downloading Properties
@property (nonatomic, copy) NSString *url;
@property (nonatomic, retain) NSURLConnection *urlConnection;
@property (nonatomic, retain) NSMutableData *asyncData;

// Parsing Properties
@property (nonatomic, retain) NSXMLParser *aggregator;
@property (nonatomic, retain) NSString *currentPath;
@property (nonatomic, retain) NSMutableString *currentText;
@property (nonatomic, retain) NSDictionary *currentElementAttributes;
@property (nonatomic, retain) MyFeedItem *item;
@property (nonatomic, retain) MyFeedInfo *info;
@property (nonatomic, copy) NSString *pathOfElementWithXHTMLType;

#pragma mark Private Methods

// Parsing Methods
- (void)reset;
- (void)abortParsing;
- (void)parsingFinished;
- (void)startParsingData:(NSData *)data;

// Dispatching to Delegate
- (void)dispatchFeedInfoToDelegate;
- (void)dispatchFeedItemToDelegate;

// Error Handling
- (void)failWithErrorCode:(int)code description:(NSString *)description;

// Misc
- (BOOL)createEnclosureFromAttributes:(NSDictionary *)attributes andAddToItem:(MyFeedItem *)currentItem;
- (BOOL)processAtomLink:(NSDictionary *)attributes andAddToMyObject:(id)MyObject;

@end