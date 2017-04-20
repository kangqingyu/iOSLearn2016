//
//  meWebViewController.m
//  百思不得姐g1
//
//  Created by kqy on 8/12/16.
//  Copyright © 2016 kqy. All rights reserved.
//

#import "meWebViewController.h"

@interface meWebViewController ()
@property (weak, nonatomic) IBOutlet UIWebView *webView;
@property (weak, nonatomic) IBOutlet UIToolbar *toolBar;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *backItem;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *forwardItem;

@end

@implementation meWebViewController
- (IBAction)reFreshClick:(id)sender {
    NSLog(@"refresh");
}
- (IBAction)backClick:(id)sender {
    NSLog(@"back");
}
- (IBAction)forwardClick:(id)sender {
    NSLog(@"forward");
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    [self.webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:self.url]]];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
