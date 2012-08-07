//
//  AggregatorAD.m
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "AggregatorAD.h"
#import "RootViewController.h"

@implementation MyAggregatorAppDelegate

@synthesize window;
@synthesize navigationController;

#pragma mark -
#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    // Override point for customization after app launch    
	[window addSubview:[navigationController view]];
    [window makeKeyAndVisible];
	return YES;
}


- (void)applicationWillTerminate:(UIApplication *)application {
	// Save data if appropriate
}

#pragma mark -
#pragma mark Memory management

- (void)dealloc {
	[navigationController release];
	[window release];
	[super dealloc];
}


@end

