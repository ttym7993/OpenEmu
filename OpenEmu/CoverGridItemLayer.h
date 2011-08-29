//
//  CoverGridItemLayer.h
//  OpenEmuMockup
//
//  Created by Christoph Leimbrock on 02.05.11.
//  Copyright 2011 none. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IKSGridItemLayer.h"

#import <QuartzCore/CoreAnimation.h>

#import "CoverGridSelectionLayer.h"
#import "CoverGridGlossLayer.h"
#import "CoverGridIndicationLayer.h"
#import "CoverGridRatingLayer.h"
@interface CoverGridItemLayer : IKSGridItemLayer <NSTextViewDelegate> {
@private
	// often reused rects
    CGRect titleRect, ratingRect;
	CGRect imageContainerRect;
	
	float imageRatio;	// keeps aspect ratio of artwork image
	NSSize lastImageSize;
	
	CoverGridSelectionLayer *selectionLayer;	// Layer for selection indicator
	CALayer *glossLayer;						// Effect overlay for artwork image 
	CoverGridIndicationLayer *indicationLayer;	// Displays status of rom (missing, accepting artwork, ....)
	CALayer *imageLayer;						// Draws artwork and black stroke around it
	CATextLayer* titleLayer;
	CoverGridRatingLayer* ratingLayer;			// Displays star rating (interaction is done on item layer)
	
	BOOL isChangingValues;
	BOOL acceptingOnDrop; // keeps track of "on drop" state
	NSTimer* dropAnimationDelayTimer;
	
	BOOL isEditingRating;
}

@property float imageRatio;

@property (readwrite, retain) CoverGridSelectionLayer *selectionLayer;
@property (readwrite, retain) CALayer *glossLayer;
@property (readwrite, retain) CoverGridIndicationLayer *indicationLayer;
@property (readwrite, retain) CALayer *imageLayer;
@property (readwrite, retain) CATextLayer *titleLayer;
@property (readwrite, retain) CoverGridRatingLayer *ratingLayer;
@end