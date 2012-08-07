//
//  RootViewController.h
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Aggregator.h"

@interface RootViewController : UITableViewController <MyAggregatorDelegate> {
	
	// Parsing
	MyAggregator *aggregator;
	NSMutableArray *parsedItems;
	
	// Displaying
	NSArray *itemsToDisplay;
	NSDateFormatter *formatter;
	
}

// Properties
@property (nonatomic, retain) NSArray *itemsToDisplay;

@end
