//
//  NSDate+InternetDateTime.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// Date format hints for parsing date from internet string
typedef enum {DateFormatHintNone, DateFormatHintRFC822, DateFormatHintRFC3339} DateFormatHint;

@interface NSDate (InternetDateTime)
+ (NSDate *)dateFromInternetDateTimeString:(NSString *)dateString formatHint:(DateFormatHint)hint;
+ (NSDate *)dateFromRFC3339String:(NSString *)dateString;
+ (NSDate *)dateFromRFC822String:(NSString *)dateString;
@end
