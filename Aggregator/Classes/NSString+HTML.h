//
//  NSString+HTML.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
//  All properties of FeedInfo and FeedItem return the raw data as provided by the feed. 
//  This content may or may not include HTML and encoded entities. If the content does include 
//  HTML, NSString+HTML will manipulate this HTML content. 


#import <Foundation/Foundation.h>

// Dependant upon GTMNSString+HTML

@interface NSString (HTML)

// Instance Methods
- (NSString *)stringByConvertingHTMLToPlainText;
- (NSString *)stringByDecodingHTMLEntities;
- (NSString *)stringByEncodingHTMLEntities;
- (NSString *)stringWithNewLinesAsBRs;
- (NSString *)stringByRemovingNewLinesAndWhitespace;

- (NSString *)stringByStrippingTags; 

@end
