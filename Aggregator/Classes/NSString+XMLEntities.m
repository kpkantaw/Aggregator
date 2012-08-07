//
//  NSString+XMLEntities.m
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#import "NSString+XMLEntities.h"


@implementation NSString (XMLEntities)

- (NSString *)stringByDecodingXMLEntities {
	return [self stringByDecodingHTMLEntities];
}

- (NSString *)stringByEncodingXMLEntities {
	return [self stringByEncodingHTMLEntities];
}

@end
