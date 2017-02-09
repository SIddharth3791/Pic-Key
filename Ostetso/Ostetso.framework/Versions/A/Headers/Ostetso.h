//
//  Ostetso.h
//  Ostetso Version 2.4
//
//  Copyright (c) 2014 PrecipiceLabs. All rights reserved.
//

#import <Foundation/Foundation.h>




@protocol OstetsoDelegate <NSObject>

@optional

// This is called when the share dialog is dismissed
- (void) shareComplete: (NSError *) error;

// The gallery has been dismissed by the user
- (void) galleryComplete: (BOOL) successful;

// The image failed to upload to the Ostetso server
- (void) uploadFailedWithError: (NSError *) error;

// There are pending notifications for the app.  Receiving this method give you the opportunity to indicate to the user
// that they have unread notifications pending on the server.  We recommend indicating this status by showing a badge
// on your gallery button.
- (void) setNotificationsPending: (BOOL) hasPendingNotifications;

// We receive a system level notification while the app is running, display this message to your
// user at an appropriate time
- (void) notificationReceived: (NSString *)message;

@end


@interface Ostetso : NSObject

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////  The following methods must be called by the client for proper Ostetso integration
///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Tell Ostetso what your app ID is
+ (void) setApplicationID:(NSString*)appID                // your app ID
                   appKey:(NSString *)appKey              // your app key
 useProductionEnvironment:(BOOL)useProductionEnvironment // YES if your app has been approved for running on the production environment and your app is release ready
                 delegate:(id<OstetsoDelegate>) delegate; // your Ostetso delegate

// Tell Ostetso that the app finished launching
+ (void) applicationDidFinishLaunchingWithOptions: (NSDictionary *)launchOptions;

// Allow the user to view the image gallery
+ (void) showGallery;

// Post an image from your app to the gallery
+ (void) shareImage: (UIImage *) uiImageToShare;

// Post an image from your app to the gallery, providing a default caption
+ (void) shareImage: (UIImage *) uiImageToShare withCaption:(NSString *)caption;

// Simply call this directly from your app delegate's handleURL
+ (BOOL) handleURL:(NSURL*) url;

// Simply call this directly from your app delegate's didRegisterForRemoteNotificationsWithDeviceToken
+ (void) registerPushToken:(NSData*)pushToken;

// Simply call this directly from your app delegate's didReceiveRemoteNotification
+ (void) didReceiveRemoteNotification:(NSDictionary*)userInfo;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////  Ostetso User Interface Customization Settings
///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Gallery View Toolbar

+ (void) setGalleryToolbarColor: (UIColor *) color;                  // Background color for the gallery toolbar.  A color here with a blurred menu will set the tint for the menu
+ (void) enableGalleryToolbarBlur: (BOOL) blurOn;                    // Enable/disable toolbar blur
+ (void) setGalleryMenuButtonListBackgroundColor: (UIColor *) color; // Background color for the filter option popup
+ (void) setGalleryMenuReturnToAppButtonImg: (UIImage *)image;       // Image icon for the return to app button
+ (void) setGalleryFilterButtonSelectedColor: (UIColor *) color;     // Background color currently selected filter button
+ (void) setGalleryFilterButtonColor: (UIColor *) color;             // Background color unselected filter buttons
+ (void) setGalleryFilterButtonFont: (UIFont *) font;                // Font for the filter button labels
+ (void) setGalleryInfoButtonImg: (UIImage *) image;                 // Image icon for the info button
+ (void) setGalleryManageAccountButtonImg: (UIImage *) image;        // Image icon for the accounts settings button

// Gallery View
+ (void) setGalleryBackgroundColor: (UIColor *) color;               // Background color for the gallery
+ (void) setGalleryBorderColor: (UIColor *) color;                   // Border color for the gallery items
+ (void) setGalleryBorderWidth: (float) width;                       // Border width for the gallery items
+ (void) setGalleryBorderRadius: (float) radius;                     // Border radius for the gallery items.   Use 0 for squared corners
+ (void) setGalleryImageSpacing: (CGSize) spacing;                   // Horizontal and Vertical space between gallery items

// Single Column Image View
+ (void) setImageViewBackgroundColor: (UIColor *) color;            // Background color for the single column view.  nil => inherit from galleryBackgroundColor
+ (void) setImageViewBorderColor: (UIColor *) color;                 // Border color for the single column view items.  nil => inherit from galleryBorderColor
+ (void) setImageViewBorderWidth: (float) width;                     // Border width for the single column view items.  -1 => inherit from galleryBorderWidth
+ (void) setImageViewBorderRadius: (float) radius;                   // Border radius for the single column view items.   Use 0 for squared corners.  -1 => inherit from galleryBorderRadius
+ (void) setImageViewImageSpacing: (float) spacing;                  // Vertical space between single column view items.  -1 => inherit from galleryImageSpacing
+ (void) setImageViewInfoBackgroundColor: (UIColor *) color;         // Background color for the app info area in the single column view (ie. "Created with..." section)
+ (void) setImageViewReturnToAppButtonImg: (UIImage *) image;        // Image icon for the return to app button
+ (void) setImageViewReturntoGalleryButtonImg: (UIImage *) image;    // Image icon for return to multi-column gallery button
+ (void) setImageViewAppStoreFont: (UIFont *) font;                  // Font for "App store" label
+ (void) setImageViewInfoFont: (UIFont *) font;                      // Font for "Created with..."
+ (void) setImageViewInfoFontiPad: (UIFont *) font;                  // Font for "Created with..." on iPad
+ (void) setImageViewAppNameFont: (UIFont *) font;                   // Font for app name
+ (void) setImageViewAppNameFontiPad: (UIFont *) font;               // Font for app name on iPad

// Gallery Button Bar
+ (void) setButtonBarBackgroundColor: (UIColor *) color;             // Background color for the button bar for each gallery item
+ (void) setLikeButtonImg: (UIImage *) image;                        // Image icon for the like button
+ (void) setLikeButtonSelectedImg: (UIImage *) image;                // Image icon for the like button selected state
+ (void) setLikeButtonDisabledImg: (UIImage *) image;                // Image icon for the like button disabled state
+ (void) setShareButtonImg: (UIImage *) image;                       // Image icon for the share button
+ (void) setShareButtonDisabledImg: (UIImage *) image;               // Image icon for the like button disabled state
+ (void) setMoreButtonImg: (UIImage *) image;                        // Image icon for the image settings button
+ (void) setImageViewButtonCountFont: (UIFont *) font;               // Font for the action count on the gallery item button bar (number of likes and shares) in the single column view
+ (void) setGalleryButtonCountFont: (UIFont *) font;                 // Font for the action count on the gallery item button bar (number of likes and shares) in the multi column view

// Account Management
+ (void) setAcctButtonTitleColor: (UIColor *) color;                 //
+ (void) setAcctButtonBackgroundColor: (UIColor *) color;
+ (void) setAcctButtonBorderColor: (UIColor *) color;
+ (void) setAcctViewBorderWidth: (float) width;
+ (void) setAcctViewBorderColor: (UIColor *) color;
+ (void) setAcctButtonFont: (UIFont *) font;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////  A few useful utilities provided by Ostetso
///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    kShareNone = 0,
    kShareFacebook,
    kShareInstagram,
    kShareEmail,
    kShareMessage,
    kShareTwitter,
    kAll
} OstetsoSharingService;

// Return the number of times an image was shared to a particular service EVER.
+ (int)  shareCountForService: (OstetsoSharingService) service;

+ (BOOL) isInternetReachable;

@end
