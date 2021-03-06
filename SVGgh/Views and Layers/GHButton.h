//
//  GHButton.h
//  SVGgh
// The MIT License (MIT)

//  Copyright (c) 2011-2014 Glenn R. Howes

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.

//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

//  Created by Glenn Howes on 1/26/14.
//

/*
  * Note you can instantiate a GHButton in a storyboard or a XIB by dragging a UIView into your view and giving it a class of GHButton. 
  * You can configure the style of the button by adding "User Defined Runtime Attributes" in XCode's "Identity Inspector"
  ***********************************
  ** Key Path      ***         Type        ***    Value    **
  ----------------------------------------------------------------
   schemeNumber             Number                 3
   artworkPath              String             Artwork/MenuButton
 -----------------------------------------------------------------
  Will make a lightly chromed button with the contents of a file in your app's bundle with the path /Artwork/MenuButton.svg
*/

#import <UIKit/UIKit.h>
#import "GHControlFactory.h"
/*! @brief a button widget that can take on various themed appearances and host vectored svg content
* @attention not a UIButton (too hard to subclass)
* @attention wire any UIAction up to the up inside event not the value changed event
*/
@interface GHButton : UIControl
@property(nonatomic, assign) ColorScheme         scheme;
/*! @property schemeNumber 
* @brief this is equivalent to the scheme property, just the one expected to be set via Storyboard or Nib
*/
@property(nonatomic, assign) NSInteger           schemeNumber;

// these are all related to how the button draws itself as part of a scheme
@property(nonatomic, assign) CGGradientRef       faceGradient;
@property(nonatomic, assign) CGGradientRef       faceGradientPressed;
@property(nonatomic, assign) CGGradientRef       faceGradientSelected;
@property(nonatomic, strong) UIColor*            textColor;
@property(nonatomic, strong) UIColor*            textColorPressed;
@property(nonatomic, strong) UIColor*            textColorSelected;
@property(nonatomic, assign) BOOL                drawsChrome; 
@property(nonatomic, strong) UIColor*            ringColor;
@property(nonatomic, strong) UIColor*            textShadowColor;
@property(nonatomic, assign) BOOL                useRadialGradient;


/*! @property title
* @brief this text (if any) will be displayed embedded in the button
*/
@property(nonatomic, strong) NSString*           title;
/*! @property artworkPath
 * @brief optional subpath to an svg file inside the resources folder, svg is displayed inside the button at appropriate size
 * @attention do not append '.svg'
 */
@property(nonatomic, strong) NSString*           artworkPath;
/*! @property selectedArtworkPath
 * @brief optional subpath to an svg file inside the resources folder, svg is displayed inside the button at appropriate size. When button is in selected state.
 * @attention do not append '.svg'
 */
@property(nonatomic, strong) NSString*           selectedArtworkPath;
/*! @property pressedArtworkPath
 * @brief optional subpath to an svg file inside the resources folder, svg is displayed inside the button at appropriate size. When button is in pressed state.
 * @attention do not append '.svg'
 */
@property(nonatomic, strong) NSString*           pressedArtworkPath;
/*! @property artworkView
 * @brief optional view to embed inside this button to display artwork. Usually used from storyboard or nib
 */
@property(nonatomic, weak)   IBOutlet UIView*    artworkView;

+(void)makeSureLoaded;
@end
