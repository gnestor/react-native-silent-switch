#import "RCTBridgeModule.h"
#import "SharkfoodMuteSwitchDetector.h"

@interface RCTSilentSwitch : NSObject <RCTBridgeModule>

@property (nonatomic,strong) SharkfoodMuteSwitchDetector* detector;

@end
