//
//  AppDelegate.h
//  vCode
//
//  Created by ruitaocc on 15/4/19.
//  Copyright (c) 2015年 ruitaocc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol InfiniTabBarDelegate;

@interface InfiniTabBar : UIScrollView <UIScrollViewDelegate, UITabBarDelegate> {
	UITabBar *aTabBar;
	UITabBar *bTabBar;
    UIButton * btnnext;
    UIButton * btnprev;
}

@property (nonatomic, assign) id<InfiniTabBarDelegate> infiniTabBarDelegate;
@property (nonatomic, retain) NSMutableArray *tabBars;
@property (nonatomic, retain) UITabBar *aTabBar;
@property (nonatomic, retain) UITabBar *bTabBar;

- (id)initWithFrame:(CGRect)frame withItems:(NSArray *)items;
- (id)initWithItemFrame:(CGRect)frame withItems:(NSArray *)items;
- (void)setBounces:(BOOL)bounces;
// Don't set more items than initially
- (void)setItems:(NSArray *)items animated:(BOOL)animated;
- (int)currentTabBarTag;
- (int)selectedItemTag;
- (BOOL)scrollToTabBarWithTag:(int)tag animated:(BOOL)animated;
- (BOOL)selectItemWithTag:(int)tag;

@end

@protocol InfiniTabBarDelegate <NSObject>
- (void)infiniTabBar:(InfiniTabBar *)tabBar didScrollToTabBarWithTag:(int)tag;
- (void)infiniTabBar:(InfiniTabBar *)tabBar didSelectItemWithTag:(int)tag;
@end