//
//  CaptureController.m
//  iPhone Simulator Capture
//
//  Copyright (c) 2010, David Beck
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without modification, 
//  are permitted provided that the following conditions are met:
//  
//  - Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer.
//  - Redistributions in binary form must reproduce the above copyright notice, 
//    this list of conditions and the following disclaimer in the documentation 
//    and/or other materials provided with the distribution.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
//  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
//  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
//  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
//  OF THE POSSIBILITY OF SUCH DAMAGE.
//  


#import "ISCController.h"
#import "SynthesizeSingleton.h"

#import "iPhone Simulator.h"

#import <QTKit/QTKit.h>

#import "ImageRect.h"
#import "ISCFrame.h"
#import "ISCRecording.h"
#import "ISCAppDelegateDelay.h"

@implementation ISCController

@synthesize menu, lengthLabel, indicator, recordButton;


#pragma mark -
#pragma mark Memory Management
- (void)dealloc
{
	self.menu = nil;
	self.lengthLabel = nil;
	self.indicator = nil;
	
	[super dealloc];
}

#pragma mark -
#pragma mark Initialization

+ (void)initialize
{
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	
	NSDictionary *appDefaults = [NSDictionary dictionaryWithObjectsAndKeys:
								 [NSNumber numberWithBool:NO], @"ISCRecordWindowVisible",
								 nil];
	
	[defaults registerDefaults:appDefaults];
}

- (id)init
{
	self = [super init];
	if (self != nil) {
		//load in our menu and window
		[NSBundle loadNibNamed:@"PluginController" owner:self];
		
		//add our menu to the application menu
		//place it right before teh window and help menu
		[[NSApp mainMenu] insertItem:menu atIndex:[[NSApp mainMenu] numberOfItems] - 2];
		
		[lengthLabel setDoubleValue:[recording length]];
		
		
		//ProcessControl *processControl = [[NSApp delegate] valueForKey:@"_simulatedProcess"];
		
		//NSLog(@"process: %@", [processControl applicationSupportDirectory]);
		
		//NSLog(@"homeDirectory: %@", [[ProcessControl sharedInstance] simulatedHomeDirectory]);
	}
	return self;
}

//A special method called by SIMBL once the application has started and all classes are initialized.
+ (void)load
{
	//force creation of shared object
	[ISCController sharedInstance];
}

//return the single static instance of the plugin object
SYNTHESIZE_SINGLETON_FOR_CLASS(ISCController)


#pragma mark -
#pragma mark ISCRecording Delegate Methods
- (void)ISCRecording:(ISCRecording *)rec renderingProgress:(double)progress
{
	[indicator setDoubleValue:progress];
}

- (void)ISCRecordingDidFinishRendering:(ISCRecording *)rec
{
	[self writeMovie:[rec movie] toURL:_saveURL];
	[_saveURL release];
	_saveURL = nil;
	
	[self showProgressBar:NO];
}

- (void)ISCRecordingLengthChanged:(ISCRecording *)rec
{
	[lengthLabel setDoubleValue:[rec length]];
}


#pragma mark -
#pragma mark Actions

//either start or stops the recording based on the new state of the sender
- (IBAction)startStopRecording:(id)sender
{
	if ([sender state] == NSOnState) {
		[recording release];
		recording = [[ISCRecording alloc] initWithDelegate:self];
		[recording start];
	} else {
		[recording stop];
	}
}

//stops recording if still recording
//saves composites image data into video and saves it
- (IBAction)saveMovie:(id)sender
{
	[recording stop];
	
	//get the filename from the user
	NSURL *filename = [self getFileName];
	
	//nil means they canceled save
	if(filename != nil) {
		if ([recording movie] == nil) {
			NSLog(@"movie nil");
			[self showProgressBar:YES];
			
			_saveURL = [filename retain];
		} else {
			[self writeMovie:[recording movie] toURL:filename];
		}
	}
}

- (void)writeMovie:(QTMovie *)movie toURL:(NSURL *)url
{
	[movie writeToFile:[url path] 
	    withAttributes:[NSDictionary dictionaryWithObject:[NSNumber numberWithBool:YES] 
										  forKey:QTMovieFlatten] 
			   error:nil];
}

//ask the user for a filename
//returns nil if the user cancels
- (NSURL *)getFileName
{
	NSSavePanel *savePanel;
	
	savePanel = [NSSavePanel savePanel];
	[savePanel setExtensionHidden:YES];
	[savePanel setCanSelectHiddenExtension:NO];
	[savePanel setTreatsFilePackagesAsDirectories:NO];
	
	//if the user doesn't cancel the save, return the filename they selected
	if ([savePanel runModal] == NSOKButton) {
		return [savePanel URL];
	}
	//return nil if the user canceled the save
	return nil;
}

- (void)showProgressBar:(BOOL)show
{
	if (show) {
		[indicator setDoubleValue:0.0];
		[[indicator window] makeKeyAndOrderFront:self];
	}
	
	NSRect frame = [[indicator window] frame];
	
	CGFloat newHeight;
	if (show) {
		newHeight = kISCPanelProgressHeight;
	} else {
		newHeight = kISCPanelRecordHeight;
	}
	
	frame.origin.y += frame.size.height - newHeight;
	frame.size.height = newHeight;
	
	[NSAnimationContext beginGrouping];
	
	[[indicator animator] setHidden:!show];
	
	[[recordButton animator] setHidden:show];
	[[lengthLabel animator] setHidden:show];
	
	[[[indicator window] animator] setFrame:frame display:YES];
	
	[NSAnimationContext endGrouping];
	
	if (show) {
		[indicator startAnimation:nil];
	} else {
		[indicator stopAnimation:nil];
	}
}

@end
