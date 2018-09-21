#if __has_include(<React/RCTBridgeModule.h>)
  #import <React/RCTBridgeModule.h>
#else
  #import "RCTBridgeModule.h"
#endif

#import "SharkfoodMuteSwitchDetector.h"

@interface RCTSilentSwitch : NSObject <RCTBridgeModule>

@property (nonatomic,strong) SharkfoodMuteSwitchDetector* detector;

@end
