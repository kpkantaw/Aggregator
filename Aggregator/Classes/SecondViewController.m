//
//  SecondViewController.m
//  Aggregator
//
//  Created by Kunal Kantawala on 12/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "SecondViewController.h"
#import "NSString+HTML.h"
#import "Aggregator.h"
#import "DetailTableViewController.h"

@implementation SecondViewController

@synthesize itemsToDisplay;

#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
	
	// Super
	[super viewDidLoad];
	
	// Setup
	self.title = @"Loading...";
	formatter = [[NSDateFormatter alloc] init];
	[formatter setDateStyle:NSDateFormatterShortStyle];
	[formatter setTimeStyle:NSDateFormatterShortStyle];
	parsedItems = [[NSMutableArray alloc] init];
	self.itemsToDisplay = [NSArray array];
	
	// Refresh button
	self.navigationItem.rightBarButtonItem = [[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh 
																							target:self 
																							action:@selector(refresh)] autorelease];
	
	// Create parser
	aggregator = [[MyAggregator alloc] initWithFeedURL:@"http://sports.espn.go.com/espn/rss/news"];
	aggregator.delegate = self;
	
	/* Set the parsing type. Options are ParseTypeFull, ParseTypeInfoOnly, ParseTypeItemsOnly. 
	 Info refers to the information about the feed, such as it's title and description. 
	 Items are the individual items or stories. */
	
	aggregator.feedParseType = ParseTypeFull; 
	
	aggregator.connectionType = ConnectionTypeAsynchronously;
	[aggregator parse];
	
}

#pragma mark -
#pragma mark Parsing

// Reset and reparse
- (void)refresh {
	if (![aggregator isParsing]) {
		self.title = @"Refreshing...";
		[parsedItems removeAllObjects];
		[aggregator parse];
		self.tableView.userInteractionEnabled = NO;
		self.tableView.alpha = 0.3;
	}
}

#pragma mark -
#pragma mark MyAggregatorDelegate

- (void)aggregatorDidStart:(MyAggregator *)parser {
	NSLog(@"Started Parsing: %@", parser.url);
}

- (void)aggregator:(MyAggregator *)parser didParseFeedInfo:(MyFeedInfo *)info {
	NSLog(@"Parsed Feed Info: “%@”", info.title);
	self.title = info.title;
}

- (void)aggregator:(MyAggregator *)parser didParseFeedItem:(MyFeedItem *)item {
	NSLog(@"Parsed Feed Item: “%@”", item.title);
	if (item) [parsedItems addObject:item];
}

- (void)aggregatorDidFinish:(MyAggregator *)parser {
	NSLog(@"Finished Parsing");
	self.itemsToDisplay = [parsedItems sortedArrayUsingDescriptors:
						   [NSArray arrayWithObject:[[[NSSortDescriptor alloc] initWithKey:@"date" 
																				 ascending:NO] autorelease]]];
	self.tableView.userInteractionEnabled = YES;
	self.tableView.alpha = 1;
	[self.tableView reloadData];
}

- (void)aggregator:(MyAggregator *)parser didFailWithError:(NSError *)error {
	NSLog(@"Finished Parsing With Error: %@", error);
	self.title = @"Failed";
	self.itemsToDisplay = [NSArray array];
	[parsedItems removeAllObjects];
	self.tableView.userInteractionEnabled = YES;
	self.tableView.alpha = 1;
	[self.tableView reloadData];
}

#pragma mark -
#pragma mark Table view data source

// Customize the number of sections in the table view.
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

// Customize the number of rows in the table view.
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return itemsToDisplay.count;
}

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier] autorelease];
		cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
    
	// Configure the cell.
	MyFeedItem *item = [itemsToDisplay objectAtIndex:indexPath.row];
	if (item) {
		
		// Process
		NSString *itemTitle = item.title ? [item.title stringByConvertingHTMLToPlainText] : @"[No Title]";
		NSString *itemSummary = item.summary ? [item.summary stringByConvertingHTMLToPlainText] : @"[No Summary]";
		
		// Set
		cell.textLabel.font = [UIFont boldSystemFontOfSize:15];
		cell.textLabel.text = itemTitle;
		NSMutableString *subtitle = [NSMutableString string];
		if (item.date) [subtitle appendFormat:@"%@: ", [formatter stringFromDate:item.date]];
		[subtitle appendString:itemSummary];
		cell.detailTextLabel.text = subtitle;
		
	}
    return cell;
}

#pragma mark -
#pragma mark Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	
	// Show detail
	DetailTableViewController *detail = [[DetailTableViewController alloc] initWithStyle:UITableViewStyleGrouped];
	detail.item = (MyFeedItem *)[itemsToDisplay objectAtIndex:indexPath.row];
	[self.navigationController pushViewController:detail animated:YES];
	[detail release];
	
	// Deselect
	[self.tableView deselectRowAtIndexPath:indexPath animated:YES];
	
}

#pragma mark -
#pragma mark Memory management

- (void)dealloc {
	[formatter release];
	[parsedItems release];
	[itemsToDisplay release];
	[aggregator release];
    [super dealloc];
}

@end
