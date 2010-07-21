/*
 *     Generated by class-dump 3.3.1 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#pragma mark -

/*
 * File: /Developer/Platforms/iPhoneSimulator.platform/Developer/Applications/iPhone Simulator.app/Contents/MacOS/SimulatorBridge
 * Arch: Intel 80x86 (i386)
 *
 *       Objective-C Garbage Collection: Unsupported
 */

@protocol SimulatorBridge
- (BOOL)installApplication:(in bycopy id)arg1 withPath:(in bycopy id)arg2 installationOptions:(in bycopy id)arg3;
- (BOOL)uninstallApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (out bycopy id)lookupInstalledApplicationsWithInstallationOptions:(in bycopy id)arg1;
- (BOOL)archiveExistsForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)removeArchiveForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)archiveAndUninstallApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)restoreArchiveForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (unsigned int)launchApplicationWithBundleId:(in bycopy id)arg1 arguments:(in bycopy id)arg2 environment:(in bycopy id)arg3 standardOutPipe:(in bycopy id)arg4 standardErrorPipe:(in bycopy id)arg5 flags:(unsigned int)arg6;
- (BOOL)processIDForDisplayIdentifier:(in bycopy id)arg1 pid:(out int *)arg2;
- (out bycopy id)frontmostApplicationIdentifier;
- (out bycopy id)copyString;
- (void)pasteString:(in bycopy id)arg1;
- (out bycopy id)copyImageData;
- (void)pasteImageData:(in bycopy id)arg1;
- (out bycopy id)copyWebArchiveData;
- (void)pasteWebArchiveData:(in bycopy id)arg1;
@end

@interface SimulatorBridge : NSObject <SimulatorBridge>
{
}

- (BOOL)installApplication:(in bycopy id)arg1 withPath:(in bycopy id)arg2 installationOptions:(in bycopy id)arg3;
- (BOOL)uninstallApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (out bycopy id)lookupInstalledApplicationsWithInstallationOptions:(in bycopy id)arg1;
- (BOOL)archiveExistsForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)removeArchiveForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)archiveAndUninstallApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (BOOL)restoreArchiveForApplication:(in bycopy id)arg1 installationOptions:(in bycopy id)arg2;
- (unsigned int)launchApplicationWithBundleId:(in bycopy id)arg1 arguments:(in bycopy id)arg2 environment:(in bycopy id)arg3 standardOutPipe:(in bycopy id)arg4 standardErrorPipe:(in bycopy id)arg5 flags:(unsigned int)arg6;
- (BOOL)processIDForDisplayIdentifier:(in bycopy id)arg1 pid:(out int *)arg2;
- (out bycopy id)frontmostApplicationIdentifier;
- (out bycopy id)copyString;
- (void)pasteString:(in bycopy id)arg1;
- (out bycopy id)copyImageData;
- (void)pasteImageData:(in bycopy id)arg1;
- (out bycopy id)copyWebArchiveData;
- (void)pasteWebArchiveData:(in bycopy id)arg1;

@end

