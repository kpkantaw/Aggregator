//
//  NSString+XMLEntities.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// Import new HTML category
#import "NSString+HTML.h"


@interface NSString (XMLEntities)

- (NSString *)stringByDecodingXMLEntities;
- (NSString *)stringByEncodingXMLEntities;

@end
