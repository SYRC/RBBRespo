//
//  ScrollTableView.h
//  SinaSH
//
//  Created by keane on 16/7/4.
//  Copyright © 2016年 keane. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NewsModel.h"

@protocol ScrollTableViewDelegate <NSObject>

- (NSInteger)tableViewNumberOfRowsInSection:(NSInteger)section;
- (NewsModel*)newsModelWithTableViewSection:(NSInteger)section andCellRow:(NSInteger)row;
- (UINib*)getNibWithTableSection:(NSInteger)section;
- (void)loadTableViewDataWithSection:(NSInteger)section;
- (void)currentPageNumberChanged:(NSInteger)currentPage;
- (void)didSelectedTableViewCellWithSection:(NSInteger)section AndRow:(NSInteger)row;

@optional
- (CGFloat)tableViewCellHeightWithSection:(NSInteger)section AndRow:(NSInteger)row;

@end

@interface ScrollTableView : UIView
@property (nonatomic,strong)UIScrollView *scrollV;
@property (nonatomic,weak)id<ScrollTableViewDelegate> delegate;
-(instancetype)initWithTableViewCount:(NSInteger)index;
-(instancetype)initWithTableViewCount:(NSInteger)count andDelegate:(id<ScrollTableViewDelegate>)delegate;

-(void)refreshTableViewWithSection:(NSInteger)index;
- (void)scrollTableViewListWithSecion:(NSInteger)section;
@end
