//
//  FeedInfo.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface MyFeedInfo : NSObject <NSCoding> {
	
	NSString *title; // Feed title
	NSString *link; // Feed link
	NSString *summary; // Feed summary / description
	
}

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *summary;

@end

