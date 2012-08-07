//
//  DetailTableViewController.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FeedItem.h"

@interface DetailTableViewController : UITableViewController {
	MyFeedItem *item;
	NSString *dateString, *summaryString;
}

@property (nonatomic, retain) MyFeedItem *item;
@property (nonatomic, retain) NSString *dateString, *summaryString;

@end
