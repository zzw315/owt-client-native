/*
 * Copyright © 2016 Intel Corporation. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <WebRTC/RTCMacros.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ICSAudioCodec) {
  ICSAudioCodecPcmu = 1,
  ICSAudioCodecPcma = 2,
  ICSAudioCodecOpus = 3,
  ICSAudioCodecG722 = 4,
  ICSAudioCodecIsac = 5,
  ICSAudioCodecIlbc = 6,
  ICSAudioCodecAac = 7,
  ICSAudioCodecAc3 = 8,
  ICSAudioCodecAsao = 9,
  ICSAudioCodecUnknown = 10,
};

typedef NS_ENUM(NSInteger, ICSVideoCodec) {
  ICSVideoCodecVP8 = 1,
  ICSVideoCodecVP9 = 2,
  ICSVideoCodecH264 = 3,
  ICSVideoCodecH265 = 4,
  ICSVideoCodecUnknown = 5,
};

typedef NS_ENUM(NSInteger, ICSAudioSourceInfo) {
  ICSAudioSourceInfoMic = 1,
  ICSAudioSourceInfoScreenCast = 2,
  ICSAudioSourceInfoFile = 3,
};

typedef NS_ENUM(NSInteger, ICSVideoSourceInfo) {
  ICSVideoSourceInfoCamera = 1,
  ICSVideoSourceInfoScreenCast = 2,
  ICSVideoSourceInfoFile = 3,
};

// This class describes a media stream's format
RTC_EXPORT
@interface ICSVideoFormat : NSObject

- (CGSize)resolution;

@end

@interface ICSAudioCodecParameters : NSObject

@property(nonatomic, assign) ICSAudioCodec name;
@property(nonatomic, assign) NSUInteger channelCount;
@property(nonatomic, assign) NSUInteger clockRate;

@end

@interface ICSVideoCodecParameters : NSObject

@property(nonatomic, assign) ICSVideoCodec name;
@property(nonatomic, strong) NSString* profile;

@end

@interface ICSAudioPublicationSettings : NSObject

@property(nonatomic, strong) ICSAudioCodecParameters* codec;

@end

@interface ICSVideoPublicationSettings : NSObject

@property(nonatomic, strong) ICSVideoCodecParameters* codec;
@property(nonatomic, assign) CGSize resolution;
@property(nonatomic, assign) CGFloat frameRate;
@property(nonatomic, assign) NSUInteger bitrate;
@property(nonatomic, assign) NSUInteger keyframeInterval;

@end

@interface ICSPublicationSettings : NSObject

@property(nonatomic, strong) ICSAudioPublicationSettings* audio;
@property(nonatomic, strong) ICSVideoPublicationSettings* video;

@end

@interface ICSAudioSubscriptionCapabilities:NSObject

@property(nonatomic, strong) NSArray<ICSAudioCodecParameters*>* codecs;

@end

@interface ICSVideoSubscriptionCapabilities:NSObject

@property(nonatomic, strong) NSArray<ICSVideoCodecParameters*>* codecs;
@property(nonatomic, strong) NSArray<NSValue*>* resolutions;
@property(nonatomic, strong) NSArray<NSNumber*>* frameRates;
//@property(nonatomic, strong) NSArray<NSNumber*>* bitrateMultipliers;

@end

@interface ICSSubscriptionCapabilities:NSObject

@property(nonatomic, strong) ICSAudioSubscriptionCapabilities* audio;
@property(nonatomic, strong) ICSVideoSubscriptionCapabilities* video;

@end

NS_ASSUME_NONNULL_END