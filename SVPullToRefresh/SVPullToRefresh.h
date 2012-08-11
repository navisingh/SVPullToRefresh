//
// SVPullToRefresh.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
///


/**
 1) Create the header view which displays the arrow, the spinner and the text messages
 2) Add it to the UIScrollView with a negavite y value
 3) Implement the UIScrollView’s delegate to set the contentInset as the header height (therefore making it visible) and ask the controller to refresh the content
 4) Once the controller is done, it sets the contentInset to zero (therefore hiding the header view)
 */

#import <UIKit/UIKit.h>

@interface SVPullToRefresh : UIView

@property (nonatomic, strong) UIColor *arrowColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;

@property (nonatomic, strong) NSDate *lastUpdatedDate;
@property (nonatomic, strong) NSDateFormatter *dateFormatter;

- (void)triggerRefresh;
- (void)startAnimating;
- (void)stopAnimating;

@end


// extends UIScrollView

@interface UIScrollView (SVPullToRefresh)

- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler;
- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;

@property (nonatomic, strong) SVPullToRefresh *pullToRefreshView;
@property (nonatomic, strong) SVPullToRefresh *infiniteScrollingView;

@property (nonatomic, assign) BOOL showsPullToRefresh;
@property (nonatomic, assign) BOOL showsInfiniteScrolling;

@end