/*
 *     Generated by class-dump 3.3.1 (64 bit).
 *     Usin iPhone Simulator 4.0 Beta 4
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 *
 */

#import <Cocoa/Cocoa.h>

@class PreferencesController;
@class MonitorWindow;
@class SimulatorFrameView;
@class SimulatorView;
@class SimulatorHomeView;
@class SimulatorGlassView;
@class SimulatorGlassWindow;
@class MonitorViewController;
@class ProcessControl;
@class SpringBoardRelay;
@class NSDistantObject;

@protocol SimulatorBridge;


#pragma mark Named Structures

struct _PurpleEventMessage {
	struct {
		unsigned int _field1;
		unsigned int _field2;
		unsigned int _field3;
		unsigned int _field4;
		unsigned int _field5;
		int _field6;
	} _field1;
	struct {
		int _field1;
		int _field2;
		struct CGPoint _field3;
		struct CGPoint _field4;
		unsigned int _field5;
		unsigned long long _field6;
		void *_field7;
		int _field8;
		int _field9;
		unsigned int _field10;
		char *_field11;
	} _field2;
};

#pragma mark -

/*
 * File: /Beta Developer/Platforms/iPhoneSimulator.platform/Developer/Applications/iPhone Simulator.app/Contents/MacOS/iPhone Simulator
 * Arch: Intel 80x86 (i386)
 *
 *       Objective-C Garbage Collection: Unsupported
 */

@protocol SimulatorViewProtocol
- (void)setMonitorViewController:(id)arg1;
@end

@interface MonitorController : NSObject
{
	PreferencesController *_preferencesController;
	NSMenu *devicesMenu;
	NSMenu *versionsMenu;
	MonitorWindow *_monitorWindow;
	NSMenuItem *_ringerMenuItem;
	NSScreen *_lastScreen;
	SimulatorFrameView *_simulatorBox;
	NSView<SimulatorViewProtocol> *_simulatorView;
	SimulatorHomeView *_homeView;
	SimulatorGlassView *_glassView;
	SimulatorGlassWindow *_glassWindow;
	int _tvOutMode;
	NSWindow *_tvOutWindow;
	MonitorViewController *_tvOutMonitorViewController;
	NSView<SimulatorViewProtocol> *_tvOutSimulatorView;
	float _rotation;
	struct CGAffineTransform _transform;
	BOOL _inRotation;
	MonitorViewController *_monitorViewController;
	NSConditionLock *eventForwardingLock;
	ProcessControl *_simulatedProcess;
	NSAppleScript *_showProgrammingGuideScript;
	struct _NSPoint _startingSimulatorViewInset;
	BOOL _useLegacyEventStructSize;
	BOOL _simulatingHardwareKeyboard;
	BOOL _sdkSupportsHostedLayerEvents;
	BOOL _demoMode;
	BOOL _enableMirrorScreens;
	BOOL _mirrorOnly;
	BOOL _mirrorScreenConnected;
	BOOL _mirrorScreenEvents;
	NSWindow *_mirrorWindow;
	NSView<SimulatorViewProtocol> *_mirrorView;
	struct CGAffineTransform _mirrorTransform;
	BOOL _mirrorNeedsRotation;
	struct _NSSize _reccomendedWindowSize;
	float _monitorWindowScale;
	int _monitorWindowType;
	NSScrollView *_monitorScrollView;
}

+ (id)sharedInstance;
+ (void)setStartingURL:(char *)arg1;
- (void)openURLInMobileSafari:(id)arg1;
- (int)desiredMonitorWindowType;
- (struct CGAffineTransform)transform;
- (id)monitorWindow;
- (float)monitorWindowScale;
- (id)simulatorBox;
- (id)simulatorView;
- (id)simulatorHomeView;
- (id)glassView;
- (id)mirrorView;
- (BOOL)mirrorNeedsRotation;
- (struct CGAffineTransform)mirrorTransform;
- (id)tvOutWindow;
- (struct _NSRect)tvOutWindowFrame;
- (void)simulatorViewNeedsDisplayOnMainThread:(id)arg1;
- (void)prepareForSpringBoardLaunch;
- (void)setUseLegacyEventStructSize:(BOOL)arg1;
- (BOOL)simulatingHardwareKeyboard;
- (void)simulatorAlreadyRunningSheetDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)awakeFromNib;
- (void)establishConnection:(id)arg1;
- (BOOL)applicationShouldHandleReopen:(id)arg1 hasVisibleWindows:(BOOL)arg2;
- (unsigned int)applicationShouldTerminate:(id)arg1;
- (void)application:(id)arg1 openFiles:(id)arg2;
- (void)dealloc;
- (void)resetContent:(id)arg1;
- (void)resetContentSheetDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (BOOL)validateMenuItem:(id)arg1;
- (float)rotation;
- (void)setNonChromeRotation;
- (void)setRotation:(float)arg1;
- (int)orientation;
- (void)copy:(id)arg1;
- (void)paste:(id)arg1;
- (void)copyScreen:(id)arg1;
- (void)toggleRotationLeft:(id)arg1;
- (void)toggleRotationRight:(id)arg1;
- (void)animateToRotation:(id)arg1;
- (void)updateWindowForDevice:(id)arg1;
- (void)simulateDevice:(id)arg1;
- (void)simulateVersion:(id)arg1;
- (void)tvOutModeChanged:(id)arg1;
- (void)homeButtonDown:(id)arg1;
- (void)homeButtonUp:(id)arg1;
- (void)homeButtonPressed:(id)arg1;
- (void)lockButtonPressed:(id)arg1;
- (void)shakeDevice:(id)arg1;
- (void)volumeUpPressed:(id)arg1;
- (void)volumeDownPressed:(id)arg1;
- (void)toggleRingerSwitch:(id)arg1;
- (void)simulateMemoryWarning:(id)arg1;
- (void)toggleInCallStatusBar:(id)arg1;
- (void)toggleHardwareKeyboard:(id)arg1;
- (void)showProgrammingGuide:(id)arg1;
- (void)windowScaleChanged:(id)arg1;
- (void)forwardEvents;
- (void)sendPreferencesChangedEvent;
- (void)sendOpenURLEvent:(id)arg1;
- (void)sendDeviceEvent:(struct _PurpleEventMessage *)arg1;

@end

@interface MonitorViewController : NSObject
{
	MonitorController *_controller;
	id _monitor;
	int _monitorType;
	void *_data;
	void *_lastData;
	unsigned int _data_rowbytes;
	unsigned int _data_width;
	unsigned int _data_height;
	unsigned int _shmemPort;
	NSLock *_lastImageLock;
	struct CGContext *_image_context;
	unsigned int _image_texture;
	_Bool _gl_initialized;
}

- (id)initWithController:(id)arg1;
- (id)initWithController:(id)arg1 monitorType:(int)arg2;
- (void)dealloc;
- (void)setMonitor:(id)arg1;
- (void)clearLastFrame;
- (void)shapeChanged:(struct CGRect)arg1;
- (void)backingChanged:(struct CGRect)arg1 depth:(unsigned int)arg2 data:(void **)arg3 rowBytes:(int *)arg4;
- (void)backingScrolled:(void *)arg1 dx:(int)arg2 dy:(int)arg3;
- (_Bool)getShmemPort:(unsigned int *)arg1 size:(unsigned int *)arg2 rowbytes:(unsigned int *)arg3 bounds:(struct CGRect *)arg4;
- (struct CGImage *)createCGImage;
- (id)bitmapImageRep;
- (void)drawImageInWindow:(id)arg1;
- (void)initGLDrawing;
- (void)blitImageToView:(id)arg1;
- (int)monitorType;

@end

@interface PurpleMonitor : NSObject
{
	NSString *_serverName;
	NSMachPort *_serverPort;
	MonitorViewController *_controller;
	BOOL _connectionEstablished;
}

- (id)initWithPortName:(id)arg1 controller:(id)arg2;
- (void)dealloc;
- (void)handleMachMessage:(void *)arg1;

@end

@interface MonitorWindow : NSWindow
{
	MonitorController *_controller;
	NSView<SimulatorViewProtocol> *_simulatorView;
	unsigned int _previousModifierFlags;
	BOOL _touchDownInStatusBar;
	BOOL _dragStartedOnScreen;
	BOOL _dragWentOffScreen;
	BOOL _previousEventWasMouseDown;
	BOOL _interceptKeyEventsForDemo;
	BOOL _allowTripleShiftSlowMotion;
	BOOL _allowFlagsChangedEvents;
	BOOL _allowScrollWheelEvents;
	BOOL _compensateForStatusBar;
}

- (BOOL)canBecomeKeyWindow;
- (void)setMonitorController:(id)arg1;
- (void)setSimulatorView:(id)arg1;
- (void)setInterceptKeyEventsForDemo:(BOOL)arg1;
- (void)setAllowTripleShiftSlowMotion:(BOOL)arg1;
- (void)setAllowFlagsChangedEvents:(BOOL)arg1;
- (void)setAllowScrollWheelEvents:(BOOL)arg1;
- (void)setCompensateForStatusBar:(BOOL)arg1;
- (void)sendEvent:(id)arg1;
- (BOOL)dragWentOffscreen:(struct _NSPoint *)arg1;
- (BOOL)touchDownInPortraitStatusBar:(struct _NSPoint)arg1;
- (struct _NSPoint)translatePointFromWindowToSimulator:(struct _NSPoint)arg1;
- (void)sendScrollEvents:(id)arg1;
- (void)copy:(id)arg1;
- (void)paste:(id)arg1;
- (void)draggingEnded:(id)arg1;
- (unsigned int)draggingEntered:(id)arg1;
- (void)draggingExited:(id)arg1;
- (BOOL)performDragOperation:(id)arg1;

@end

@interface PreferencesController : NSObject
{
	MonitorController *_monitorController;
}

+ (void)initialize;
+ (void)createMobileSafariBookmarks:(BOOL)arg1;
+ (void)registerDefaults;
- (void)copyDesktopSafariBookmarks:(id)arg1;

@end

@interface SimulatorGlassView : NSView
{
	struct _NSPoint _mousePoint;
	struct _NSPoint _pinchPoint;
	struct _NSPoint _mirrorPoint;
	BOOL _fingerDown;
	BOOL _acceptingDrag;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (BOOL)isOpaque;
- (void)drawRect:(struct _NSRect)arg1;
- (BOOL)isIgnoredPoint:(struct _NSPoint)arg1;
- (void)setPinchPoint:(struct _NSPoint)arg1;
- (void)resetPinchPoint;
- (struct _NSPoint)pinchPoint;
- (void)setMousePoint:(struct _NSPoint)arg1;
- (void)resetMousePoint;
- (struct _NSPoint)mousePoint;
- (void)setMirrorPoint:(struct _NSPoint)arg1;
- (void)resetMirrorPoint;
- (struct _NSPoint)mirrorPoint;
- (void)setFingerDown:(BOOL)arg1;
- (BOOL)fingerDown;
- (void)setAcceptingDrag:(BOOL)arg1;
- (void)drawCenterAtPoint:(struct _NSPoint)arg1;
- (void)drawFingerAtPoint:(struct _NSPoint)arg1;

@end

@interface SimulatorGlassWindow : NSWindow
{
}

- (BOOL)ignoresMouseEvents;
- (BOOL)isOpaque;
- (id)backgroundColor;
- (BOOL)hasShadow;
- (BOOL)accessibilityIsIgnored;

@end

@interface SimulatorView : NSView <SimulatorViewProtocol>
{
	MonitorViewController *_monitorViewController;
}

- (void)dealloc;
- (void)drawRect:(struct _NSRect)arg1;
- (BOOL)mouseDownCanMoveWindow;
- (void)setMonitorViewController:(id)arg1;

@end

@interface SimulatorOpenGLView : NSOpenGLView <SimulatorViewProtocol>
{
	MonitorViewController *_monitorViewController;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)prepareOpenGL;
- (void)drawRect:(struct _NSRect)arg1;
- (BOOL)mouseDownCanMoveWindow;
- (void)setMonitorViewController:(id)arg1;

@end

@interface ProcessControl : NSObject
{
	NSString *_applicationSupportDirectory;
	SpringBoardRelay *_springBoardRelay;
	NSTask *_childTask;
	NSTask *_bridgeTask;
	NSDistantObject<SimulatorBridge> *_bridgeDistantObject;
	BOOL _crashDialogShowing;
	NSString *_sessionUUID;
	NSString *_sessionOwner;
	NSString *_sessionSDKRoot;
	NSString *_sessionDeviceInfo;
	NSString *_sessionApplicationIdentifier;
	int _grandchildPid;
	BOOL _launchdJobsLoaded;
	BOOL _homeButtonPressed;
	BOOL _debugLoggingEnabled;
	BOOL _usingDashcode;
	BOOL _usingDashcodeFullScreen;
	BOOL _usingInterfaceBuilder;
}

+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (void)clearSessionProperties;
- (void)migrateToVersionedHomeDirectories;
- (void)copyGlobalPreferencesPlist;
- (void)clearMobileInstallationCache;
- (id)promptForSDKRoot;
- (id)promptForApplicationPath:(id)arg1;
- (id)sdkRootPath;
- (id)getProcessPath;
- (id)applicationSupportDirectory;
- (id)simulatedHomeDirectoryVersioned:(BOOL)arg1;
- (id)simulatedHomeDirectory;
- (id)bridgeDistantObject;
- (void)startSession:(id)arg1;
- (void)endSession:(id)arg1;
- (void)delayedKill:(id)arg1;
- (BOOL)userNavigatedFromSession;
- (BOOL)shouldQuitOnSessionEnd;
- (id)mobileInstallationOptionsForApplicationType:(struct __CFString *)arg1;
- (BOOL)installApplication:(id)arg1 withPath:(id)arg2;
- (BOOL)uninstallApplication:(id)arg1;
- (BOOL)isUserApplicationInstalled:(id)arg1;
- (BOOL)isSystemApplicationInstalled:(id)arg1;
- (id)lookupInstalledApplications:(struct __CFString *)arg1;
- (BOOL)archiveExistsForApplication:(id)arg1;
- (BOOL)removeArchiveForApplication:(id)arg1;
- (BOOL)archiveAndUninstallApplication:(id)arg1;
- (BOOL)restoreArchiveForApplication:(id)arg1;
- (id)pathToWebApps;
- (id)webAppIdentifier;
- (BOOL)installWebApp:(id)arg1 withIdentifier:(id)arg2;
- (id)createTask;
- (id)createArguments;
- (id)createEnvironment;
- (void)launchBridge;
- (BOOL)setupBridge;
- (void)terminateBridge;
- (void)loadLaunchdJobs;
- (void)fixPermissionsForLaunchdPlist:(id)arg1;
- (void)unloadLaunchdJobs;
- (void)invalidateBridge;
- (void)launch;
- (void)restart;
- (void)terminate;
- (void)setHomeButtonPressed:(BOOL)arg1;
- (void)endSessionForQuit;
- (void)checkStatus:(id)arg1;
- (void)_checkStatus:(id)arg1;
- (void)crashSheetDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)watchGrandchildProcess:(int)arg1;
- (void)postLaunchedMessageWithUserInfo:(id)arg1;
- (void)handleGrandchildProcessEnded:(id)arg1;
- (void)setGrandchildPid:(int)arg1;
- (id)sessionUUID;
- (void)setSessionUUID:(id)arg1;
- (void)setSessionOwner:(id)arg1;
- (void)setSessionSDKRoot:(id)arg1;
- (void)setSessionDeviceInfo:(id)arg1;
- (void)setSessionApplicationIdentifier:(id)arg1;
- (void)debugLog:(id)arg1;

@end

@interface DeviceVersions : NSObject
{
	NSMutableDictionary *_deviceMap;
	NSMutableDictionary *_versionMap;
	NSString *_sdksDirectoryPath;
	BOOL _allowOther;
}

+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (BOOL)checkFileAtPath:(id)arg1;
- (void)createDeviceMap;
- (void)loadDevicesAtPath:(id)arg1;
- (void)createVersionMap;
- (id)deviceAndVersionInfo;
- (id)productTypes;
- (id)allDevices;
- (id)currentDevice;
- (void)setCurrentDevice:(id)arg1;
- (id)currentDeviceInfo;
- (id)capabilitiesPlistForCurrentDevice;
- (struct _NSSize)sizeForCurrentDevice;
- (float)scaleForCurrentDevice;
- (id)chromeImageForCurrentDevice;
- (id)homeImageForCurrentDevice;
- (struct _NSPoint)homeOriginForCurrentDevice;
- (id)allVersions;
- (id)allSDKRoots;
- (id)shortVersionString;
- (id)currentSDKRoot;
- (void)setCurrentSDKRoot:(id)arg1;
- (id)sdksDirectoryPath;
- (id)deviceInfoForProductType:(int)arg1;
- (BOOL)updateSDKForCurrentDevice;
- (BOOL)updateDeviceForCurrentSDK;
- (BOOL)sdkSupportsPasteBoard:(id)arg1;
- (BOOL)sdkSupportsShake:(id)arg1;
- (BOOL)sdkSupportsAutomaticUpgradeInstall:(id)arg1;
- (BOOL)sdkSupportsLiveInCallStatusBar:(id)arg1;
- (BOOL)sdkSupportsInCallStatusBar:(id)arg1;
- (BOOL)sdkUsesLegacyEventStruct:(id)arg1;
- (BOOL)sdkUsesLegacyKeyEventStruct:(id)arg1;
- (BOOL)sdkSupportsHardwareKeyboard:(id)arg1;
- (BOOL)sdkSupportsAccessibility:(id)arg1;
- (BOOL)sdkSupportsTVOut:(id)arg1;
- (BOOL)sdkSupportsHostedLayerEvents:(id)arg1;
- (BOOL)sdkIsComplete:(id)arg1;
- (id)sdkBasedOnVersionString:(id)arg1 inverseSearch:(BOOL)arg2;
- (id)sdkPathForVersion:(id)arg1;
- (id)versionForSDKPath:(id)arg1;
- (float)versionFloatForSDKPath:(id)arg1;
- (id)systemPlistFromSDKPath:(id)arg1;
- (id)sdkPlistFromSDKPath:(id)arg1;
- (void)updateUseLegacyEventStructSize:(id)arg1;

@end

@interface SpringBoardRelay : NSObject
{
	BOOL _busy;
	NSDictionary *_sessionDictionary;
	double _timeout;
	ProcessControl *_processControl;
}

- (void)dealloc;
- (void)setProcessControl:(id)arg1;
- (id)openApplication:(id)arg1;
- (void)sendLaunchApplicationToSpringBoard;
- (void)checkForPID;

@end

@interface SimulatorFrameView : NSView
{
	BOOL _shadowNeedsDisplay;
}

+ (id)frameImage;
+ (struct _NSSize)frameSize;
- (id)initWithFrame:(struct _NSRect)arg1;
- (BOOL)isOpaque;
- (BOOL)mouseDownCanMoveWindow;
- (void)drawRect:(struct _NSRect)arg1;
- (void)setShadowNeedsDisplay:(BOOL)arg1;

@end

@interface SimulatorHomeView : NSView
{
	BOOL _pressed;
}

+ (id)pressedHomeImage;
- (id)initWithFrame:(struct _NSRect)arg1;
- (BOOL)isOpaque;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (BOOL)mouseDownCanMoveWindow;
- (void)mouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)drawRect:(struct _NSRect)arg1;

@end

@interface LaunchdUtilities : NSObject
{
}

+ (void)deleteJobWithLabel:(id)arg1;
+ (id)allJobLabels;

@end

@interface PurpleHardware : NSObject
{
	struct _NSSize _screenPixels;
	float _screenScaleFactor;
}

+ (id)sharedInstance;
- (void)setScreenPixels:(struct _NSSize)arg1;
- (struct _NSSize)screenPixels;
- (struct _NSSize)screenPoints;
- (void)setScreenScaleFactor:(float)arg1;
- (float)screenScaleFactor;

@end

@interface DeviceInfo : NSObject
{
	NSString *displayName;
	NSString *bundlePath;
	NSString *minimumVersionString;
	NSString *capabilitiesPlist;
	struct _NSSize size;
	struct _NSSize forceSize;
	float scale;
	BOOL canTether;
	BOOL invertX;
	BOOL invertY;
	BOOL transformedTouch;
	NSString *chromeImageName;
	NSImage *chromeImage;
	NSString *homeImageName;
	NSImage *homeImage;
	float homeOriginY;
	struct _NSPoint homeOrigin;
	int productType;
	NSString *productClass;
}

+ (id)device;
+ (id)deviceWithPath:(id)arg1;
- (id)init;
- (void)dealloc;
- (BOOL)isForcingSize;
- (struct _NSPoint)forceOrigin;
- (id)chromeImage;
- (id)homeImage;
- (id)imageWithName:(id)arg1;
- (id)productClass;
- (void)setProductClass:(id)arg1;
- (int)productType;
- (void)setProductType:(int)arg1;
- (struct _NSPoint)homeOrigin;
- (void)setHomeOrigin:(struct _NSPoint)arg1;
- (id)homeImageName;
- (void)setHomeImageName:(id)arg1;
- (id)chromeImageName;
- (void)setChromeImageName:(id)arg1;
- (BOOL)transformedTouch;
- (void)setTransformedTouch:(BOOL)arg1;
- (BOOL)invertY;
- (void)setInvertY:(BOOL)arg1;
- (BOOL)invertX;
- (void)setInvertX:(BOOL)arg1;
- (BOOL)canTether;
- (void)setCanTether:(BOOL)arg1;
- (float)scale;
- (void)setScale:(float)arg1;
- (struct _NSSize)forceSize;
- (void)setForceSize:(struct _NSSize)arg1;
- (struct _NSSize)size;
- (void)setSize:(struct _NSSize)arg1;
- (id)capabilitiesPlist;
- (void)setCapabilitiesPlist:(id)arg1;
- (id)minimumVersionString;
- (void)setMinimumVersionString:(id)arg1;
- (id)bundlePath;
- (void)setBundlePath:(id)arg1;
- (id)displayName;
- (void)setDisplayName:(id)arg1;

@end

@interface MockiPhoneAccessibilityElement : NSObject
{
	NSDictionary *_data;
	NSView *_parent;
}

+ (void)initialize;
- (id)initWithDictionary:(id)arg1 parent:(id)arg2;
- (void)updateDictionary:(id)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityActionNames;
- (int)pid;
- (BOOL)accessibilityIsIgnored;
- (id)accessibilityActionDescription:(id)arg1;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (id)roleDescription;
- (id)accessibilityAttributeValue:(id)arg1;
- (void)performPressAction;
- (void)performIncrementAction;
- (void)performDecrementAction;
- (void)accessibilityPerformAction:(id)arg1;
- (BOOL)accessibilityShouldUseUniqueId;
- (void)dealloc;

@end

@interface MonitorController (private)
- (BOOL)newWindowRequiredForRotation;
- (void)cleanupWindows:(BOOL)arg1;
- (void)setupWindows:(BOOL)arg1;
- (void)setupMonitorWindow;
- (struct _NSSize)simulatorViewSize;
- (struct _NSRect)scrollDocumentFrame;
- (struct _NSSize)simulatorViewFrameDifference;
- (void)updateScaledSimulatorFrame;
- (void)updateMonitorWindowLevel;
- (void)moveWindowOnScreen;
- (void)setupTVOutMonitorWindow;
- (void)setupGlassWindow;
- (void)updateGlassWindow;
- (void)updateScreenInfo:(id)arg1;
- (void)populateDeviceMenu;
- (void)populateVersionMenu;
- (void)insertOtherMenu;
- (BOOL)orientationIsPortraitish;
- (int)orientationFromRadians:(float)arg1;
- (float)radiansFromOrientation:(int)arg1;
- (void)toggleRotationToOrientation:(int)arg1;
- (void)rotationTimout;
- (void)sendButtonEvent:(int)arg1;
@end

@interface NSTask (SimulatorRunLoop)
- (void)waitUntilExitWithoutSpinningRunLoop;
@end

@interface SimulatorOpenGLView (Accessibility)
- (id)superAccessibilityAttributeValue:(id)arg1;
- (id)superAccessibilityAttributeNames;
- (BOOL)accessibilityIsIgnored;
- (id)accessibilityHitTest:(struct _NSPoint)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
@end

@interface SimulatorView (Accessibility)
- (id)superAccessibilityAttributeValue:(id)arg1;
- (id)superAccessibilityAttributeNames;
- (BOOL)accessibilityIsIgnored;
- (id)accessibilityHitTest:(struct _NSPoint)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
@end

@interface MonitorWindow (Accessibility)
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityHitTest:(struct _NSPoint)arg1;
@end

@interface SimulatorHomeView (Accessibility)
- (BOOL)accessibilityIsIgnored;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityActionNames;
- (id)accessibilityActionDescription:(id)arg1;
- (void)accessibilityPerformAction:(id)arg1;
@end

@interface MonitorViewController (Accessibility)
- (id)_elementForData:(id)arg1;
- (void)_handleAccessibilityScreenChange;
- (void)_updateAccessibilityAvailability;
- (void)_bridgeTerminated;
- (void)_initializeAccessibility;
- (BOOL)accessibilityIsIgnored;
- (id)accessibilityHitTest:(struct _NSPoint)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
@end

