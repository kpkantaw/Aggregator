//
//  FeedInfo.m
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#import "FeedInfo.h"

#define EXCERPT(str, len) (([str length] > len) ? [[str substringToIndex:len-1] stringByAppendingString:@"…"] : str)

@implementation MyFeedInfo

@synthesize title, link, summary;

#pragma mark NSObject

- (NSString *)description {
	NSMutableString *string = [[NSMutableString alloc] initWithString:@"MyFeedInfo: "];
	if (title)   [string appendFormat:@"“%@”", EXCERPT(title, 50)];
	return [string autorelease];
}

- (void)dealloc {
	[title release];
	[link release];
	[summary release];
	[super dealloc];
}

#pragma mark NSCoding

- (id)initWithCoder:(NSCoder *)decoder {
	if (self = [super init]) {
		title = [[decoder decodeObjectForKey:@"title"] retain];
		link = [[decoder decodeObjectForKey:@"link"] retain];
		summary = [[decoder decodeObjectForKey:@"summary"] retain];
	}
	return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
	if (title) [encoder encodeObject:title forKey:@"title"];
	if (link) [encoder encodeObject:link forKey:@"link"];
	if (summary) [encoder encodeObject:summary forKey:@"summary"];
}

@end
