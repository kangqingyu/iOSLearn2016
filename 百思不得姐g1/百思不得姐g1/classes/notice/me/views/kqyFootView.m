//
//  kqyFootView.m
//  百思不得姐g1
//
//  Created by kqy on 8/10/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "kqyFootView.h"
#import "AFNetworking.h"
#import "MJExtension.h"
#import "meSquareModel.h"
#import "UIImageView+WebCache.h"
#import "UIButton+WebCache.h"
#import "loginBtn.h"
@implementation kqyFootView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        NSMutableDictionary *params = [NSMutableDictionary dictionary];
        params[@"a"] = @"square";
        params[@"c"] = @"topic";
        
        AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
//        manager.securityPolicy.validatesDomainName = NO;// 这个可以忽略HTTP7的安全。
        
        [manager GET:@"http://api.budejie.com/api/api_open.php" parameters:params success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            
        NSArray *squares = [meSquareModel mj_objectArrayWithKeyValuesArray:responseObject[@"square_list"]];
            [self createSquares:squares];
//            kqyLog(@"success: %@   %@",[responseObject class], responseObject);
//            [responseObject writeToFile:@"/Users/kqy/Desktop/baisi081001.plist" atomically:YES ];
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            kqyLog(@"fail: %@", error);
        }];
        
//        [manager GET:@"http://api.budejie.com/api/api_open.php" parameters:params  progress:^(NSProgress * _Nonnull downloadProgress) {
//            
//        } success :^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
//            
//        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
//            
//            
//        }];
        
        
    }
    return self;
}
- (void)createSquares:(NSArray *)squares {
    NSInteger totalNumber = squares.count;
    NSInteger columns = 4 ;
    CGFloat btnWidth = self.frame.size.width / columns;
    for (int i = 0; i < totalNumber; ++i) {
        int colIdx = i % columns;
        int rowIdx = i / columns;
        meSquareModel *squarMod = squares[i];
        
        loginBtn *button = [[loginBtn alloc] init];
        CGFloat btnX = colIdx * btnWidth;
        CGFloat btnY = rowIdx * btnWidth;
        button.frame = CGRectMake(btnX, btnY, btnWidth, btnWidth);
        button.backgroundColor = kqyRandomColor;
        [self addSubview:button];
        [button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchUpInside];
        
        [button setTitle:squarMod.name forState:UIControlStateNormal];
//        [button setImage:[UIImage imageNamed:@"setup-head-default"] forState:UIControlStateNormal];
//        [[SDWebImageManager sharedManager] downloadImageWithURL:[NSURL URLWithString:squarMod.icon] options:0 progress:nil completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
//            [button setImage:image forState:UIControlStateNormal];
//        }];
        [button sd_setImageWithURL:[NSURL URLWithString:squarMod.icon] forState:UIControlStateNormal placeholderImage:[UIImage imageNamed:@"setup-head-default"]];
    }
//    CGFloat footHeight = CGRectGetMaxY([self.subviews lastObject].frame);
//    CGFloat footHeight = CGRectGetMaxY(self.subviews.lastObject.frame);
//    CGRect tempFrame = self.frame;
//    tempFrame.origin.y = footHeight;
//    self.frame = tempFrame;
    self.kqy_height = self.subviews.lastObject.kqy_bottom;
    UITableView *supeTabV = (UITableView *)self.superview;

    supeTabV.tableFooterView = self;

}
- (void) buttonCLick:(UIButton *)button {
//    meSquareModel *squareMod =
}
@end
