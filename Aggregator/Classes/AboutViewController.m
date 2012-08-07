//
//  AboutViewController.m
//  iAdvocate99
//
//  Created by Kunal Kantawala on 11/19/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "AboutViewController.h"


@implementation AboutViewController

@synthesize textviewAbout;

-(void)viewWillAppear:(BOOL)animated 
{
    
	[textviewAbout setEditable:NO];
	textviewAbout.text = @"Aggregator is an iPhone application developed in ObjectiveC for downloading and parsing RSS and Atom web feeds. Icons for individual tabs and application logo are used from Glyphsih.com under a Creative Commons Attribution license as stated on the website- http://glyphish.com/.[CSE 996 - M001 Master's Project]. Required OS: iOS 4.0 or above";
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
