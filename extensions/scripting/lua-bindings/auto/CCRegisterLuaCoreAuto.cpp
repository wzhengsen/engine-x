#include "scripting/lua-bindings/auto/CCRegisterLuaCoreAuto.hpp"
#include "cocos2d.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCPipelineDescriptor.h"
#include "renderer/backend/RenderTarget.h"
#include "navmesh/CCNavMesh.h"
#include "ui/UIWidget.h"
#include "base/TGAlib.h"
namespace cocos2d{
extern void RegisterLuaCoreClonableAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRefAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTextVAlignmentAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTextHAlignmentAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGlyphCollectionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLabelEffectAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerCustomAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTexture2DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLabelProtocolAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreComponentAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePHYSICSSHAPE_MATERIAL_DEFAULTAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePHYSICSBODY_MATERIAL_DEFAULTAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSceneAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventTouchAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreResolutionPolicyAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGLViewAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMATRIX_STACK_TYPEAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDirectorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTimerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSchedulerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAsyncTaskPoolAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFiniteTimeActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpeedAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFollowAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreImageAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePolygonInfoAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAutoPolygonAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpriteFrameAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAnimationFrameAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAnimationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionIntervalAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSequenceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRepeatAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRepeatForeverAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpawnAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRotateToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRotateByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMoveByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMoveToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSkewToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSkewByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreJumpByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreJumpToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreBezierByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreBezierToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreScaleToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreScaleByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreBlinkAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTintToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTintByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDelayTimeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAnimateAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTargetedActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionFloatAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventKeyboardAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePropertiesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreUserDefaultAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFileUtilsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLanguageTypeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreZipAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRZipAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreWZipAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventAccelerationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventCustomAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventDispatcherAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventFocusAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerAccelerationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerFocusAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerKeyboardAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventMouseAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerTouchOneByOneAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEventListenerTouchAllAtOnceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionCameraAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreOrbitCameraAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePointArrayAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCardinalSplineToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCardinalSplineByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCatmullRomToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCatmullRomByAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionEaseAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseRateActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseExponentialInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseExponentialOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseExponentialInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseSineInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseSineOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseSineInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBounceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBounceInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBounceOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBounceInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBackInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBackOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBackInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuadraticActionInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuadraticActionOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuadraticActionInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuarticActionInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuarticActionOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuarticActionInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuinticActionInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuinticActionOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseQuinticActionInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCircleActionInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCircleActionOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCircleActionInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCubicActionInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCubicActionOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseCubicActionInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseElasticAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseElasticInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseElasticOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseElasticInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreEaseBezierActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionInstantAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreShowAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreHideAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreToggleVisibilityAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRemoveSelfAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFlipXAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFlipYAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePlaceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCallFuncAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGridActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGrid3DActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTiledGrid3DActionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreStopGridAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreReuseGridAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreWaves3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFlipX3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFlipY3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLens3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRipple3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreShaky3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLiquidAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreWavesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTwirlAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionManagerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreProgressToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreProgressFromToAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreShuffleTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeOutTRTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeOutBLTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeOutUpTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFadeOutDownTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTurnOffTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreWavesTiles3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreJumpTiles3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSplitRowsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSplitColsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionTweenDelegateAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreActionTweenAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAtlasNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreClippingNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreClippingRectangleNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDrawNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLabelAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLabelAtlasAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTouchAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLayerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLayerColorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLayerGradientAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLayerRadialGradientAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLayerMultiplexAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemLabelAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemAtlasFontAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemFontAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemSpriteAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemImageAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuItemToggleAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMenuAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMotionStreakAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreNodeGridAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleBatchNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSystemAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSystemQuadAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleFireAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleFireworksAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSunAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleGalaxyAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleFlowerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleMeteorAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSpiralAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleExplosionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSmokeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleSnowAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParticleRainAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreProgressTimerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreProtectedNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpriteAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRenderTextureAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionEaseSceneAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSceneAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSceneOrientedAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionRotoZoomAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionJumpZoomAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionMoveInLAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionMoveInRAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionMoveInTAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionMoveInBAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSlideInLAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSlideInRAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSlideInBAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSlideInTAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionShrinkGrowAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFlipXAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFlipYAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFlipAngularAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionZoomFlipXAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionZoomFlipYAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionZoomFlipAngularAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFadeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionCrossFadeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionTurnOffTilesAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSplitColsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionSplitRowsAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFadeTRAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFadeBLAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFadeUpAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionFadeDownAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionPageTurnAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressRadialCCWAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressRadialCWAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressHorizontalAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressVerticalAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressInOutAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTransitionProgressOutInAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraFlagAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraBackgroundBrushAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraBackgroundDepthBrushAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraBackgroundColorBrushAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCameraBackgroundSkyBoxBrushAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGridBaseAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGrid3DAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLightTypeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreLightFlagAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreBaseLightAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDirectionLightAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePointLightAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpotLightAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAmbientLightAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRenderStateAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTechniqueAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreMaterialAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCorePassAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreRendererAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTextureCacheAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDeviceAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreApplicationProtocolAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreApplicationAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreGLViewImplAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreAnimationCacheAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpriteBatchNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreSpriteFrameCacheAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreParallaxNodeAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXObjectGroupAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXTileFlags_Auto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXLayerInfoAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXTilesetInfoAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXMapInfoAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTileMapAtlasAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFastTMXLayerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXTileAnimTaskAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreTMXTileAnimManagerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreFastTMXTiledMapAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreCryptoAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreConnectionAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreServerAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreClientAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDownloadTaskAuto(cocos2d::extension::Lua&);
extern void RegisterLuaCoreDownloaderAuto(cocos2d::extension::Lua&);
void RegisterLuaCoreAuto(cocos2d::extension::Lua& lua){
lua["cc"]=lua.get_or("cc",lua.create_table());
RegisterLuaCoreClonableAuto(lua);
RegisterLuaCoreRefAuto(lua);
RegisterLuaCoreTextVAlignmentAuto(lua);
RegisterLuaCoreTextHAlignmentAuto(lua);
RegisterLuaCoreGlyphCollectionAuto(lua);
RegisterLuaCoreLabelEffectAuto(lua);
RegisterLuaCoreEventListenerAuto(lua);
RegisterLuaCoreEventListenerCustomAuto(lua);
RegisterLuaCoreTexture2DAuto(lua);
RegisterLuaCoreLabelProtocolAuto(lua);
RegisterLuaCoreComponentAuto(lua);
RegisterLuaCorePHYSICSSHAPE_MATERIAL_DEFAULTAuto(lua);
RegisterLuaCorePHYSICSBODY_MATERIAL_DEFAULTAuto(lua);
RegisterLuaCoreNodeAuto(lua);
RegisterLuaCoreSceneAuto(lua);
RegisterLuaCoreEventAuto(lua);
RegisterLuaCoreEventTouchAuto(lua);
RegisterLuaCoreResolutionPolicyAuto(lua);
RegisterLuaCoreGLViewAuto(lua);
RegisterLuaCoreMATRIX_STACK_TYPEAuto(lua);
RegisterLuaCoreDirectorAuto(lua);
RegisterLuaCoreTimerAuto(lua);
RegisterLuaCoreSchedulerAuto(lua);
RegisterLuaCoreAsyncTaskPoolAuto(lua);
RegisterLuaCoreActionAuto(lua);
RegisterLuaCoreFiniteTimeActionAuto(lua);
RegisterLuaCoreSpeedAuto(lua);
RegisterLuaCoreFollowAuto(lua);
RegisterLuaCoreImageAuto(lua);
RegisterLuaCorePolygonInfoAuto(lua);
RegisterLuaCoreAutoPolygonAuto(lua);
RegisterLuaCoreSpriteFrameAuto(lua);
RegisterLuaCoreAnimationFrameAuto(lua);
RegisterLuaCoreAnimationAuto(lua);
RegisterLuaCoreActionIntervalAuto(lua);
RegisterLuaCoreSequenceAuto(lua);
RegisterLuaCoreRepeatAuto(lua);
RegisterLuaCoreRepeatForeverAuto(lua);
RegisterLuaCoreSpawnAuto(lua);
RegisterLuaCoreRotateToAuto(lua);
RegisterLuaCoreRotateByAuto(lua);
RegisterLuaCoreMoveByAuto(lua);
RegisterLuaCoreMoveToAuto(lua);
RegisterLuaCoreSkewToAuto(lua);
RegisterLuaCoreSkewByAuto(lua);
RegisterLuaCoreJumpByAuto(lua);
RegisterLuaCoreJumpToAuto(lua);
RegisterLuaCoreBezierByAuto(lua);
RegisterLuaCoreBezierToAuto(lua);
RegisterLuaCoreScaleToAuto(lua);
RegisterLuaCoreScaleByAuto(lua);
RegisterLuaCoreBlinkAuto(lua);
RegisterLuaCoreFadeToAuto(lua);
RegisterLuaCoreFadeInAuto(lua);
RegisterLuaCoreFadeOutAuto(lua);
RegisterLuaCoreTintToAuto(lua);
RegisterLuaCoreTintByAuto(lua);
RegisterLuaCoreDelayTimeAuto(lua);
RegisterLuaCoreAnimateAuto(lua);
RegisterLuaCoreTargetedActionAuto(lua);
RegisterLuaCoreActionFloatAuto(lua);
RegisterLuaCoreEventKeyboardAuto(lua);
RegisterLuaCorePropertiesAuto(lua);
RegisterLuaCoreUserDefaultAuto(lua);
RegisterLuaCoreFileUtilsAuto(lua);
RegisterLuaCoreLanguageTypeAuto(lua);
RegisterLuaCoreZipAuto(lua);
RegisterLuaCoreRZipAuto(lua);
RegisterLuaCoreWZipAuto(lua);
RegisterLuaCoreEventAccelerationAuto(lua);
RegisterLuaCoreEventCustomAuto(lua);
RegisterLuaCoreEventDispatcherAuto(lua);
RegisterLuaCoreEventFocusAuto(lua);
RegisterLuaCoreEventListenerAccelerationAuto(lua);
RegisterLuaCoreEventListenerFocusAuto(lua);
RegisterLuaCoreEventListenerKeyboardAuto(lua);
RegisterLuaCoreEventMouseAuto(lua);
RegisterLuaCoreEventListenerTouchOneByOneAuto(lua);
RegisterLuaCoreEventListenerTouchAllAtOnceAuto(lua);
RegisterLuaCoreActionCameraAuto(lua);
RegisterLuaCoreOrbitCameraAuto(lua);
RegisterLuaCorePointArrayAuto(lua);
RegisterLuaCoreCardinalSplineToAuto(lua);
RegisterLuaCoreCardinalSplineByAuto(lua);
RegisterLuaCoreCatmullRomToAuto(lua);
RegisterLuaCoreCatmullRomByAuto(lua);
RegisterLuaCoreActionEaseAuto(lua);
RegisterLuaCoreEaseRateActionAuto(lua);
RegisterLuaCoreEaseExponentialInAuto(lua);
RegisterLuaCoreEaseExponentialOutAuto(lua);
RegisterLuaCoreEaseExponentialInOutAuto(lua);
RegisterLuaCoreEaseSineInAuto(lua);
RegisterLuaCoreEaseSineOutAuto(lua);
RegisterLuaCoreEaseSineInOutAuto(lua);
RegisterLuaCoreEaseBounceAuto(lua);
RegisterLuaCoreEaseBounceInAuto(lua);
RegisterLuaCoreEaseBounceOutAuto(lua);
RegisterLuaCoreEaseBounceInOutAuto(lua);
RegisterLuaCoreEaseBackInAuto(lua);
RegisterLuaCoreEaseBackOutAuto(lua);
RegisterLuaCoreEaseBackInOutAuto(lua);
RegisterLuaCoreEaseQuadraticActionInAuto(lua);
RegisterLuaCoreEaseQuadraticActionOutAuto(lua);
RegisterLuaCoreEaseQuadraticActionInOutAuto(lua);
RegisterLuaCoreEaseQuarticActionInAuto(lua);
RegisterLuaCoreEaseQuarticActionOutAuto(lua);
RegisterLuaCoreEaseQuarticActionInOutAuto(lua);
RegisterLuaCoreEaseQuinticActionInAuto(lua);
RegisterLuaCoreEaseQuinticActionOutAuto(lua);
RegisterLuaCoreEaseQuinticActionInOutAuto(lua);
RegisterLuaCoreEaseCircleActionInAuto(lua);
RegisterLuaCoreEaseCircleActionOutAuto(lua);
RegisterLuaCoreEaseCircleActionInOutAuto(lua);
RegisterLuaCoreEaseCubicActionInAuto(lua);
RegisterLuaCoreEaseCubicActionOutAuto(lua);
RegisterLuaCoreEaseCubicActionInOutAuto(lua);
RegisterLuaCoreEaseInAuto(lua);
RegisterLuaCoreEaseOutAuto(lua);
RegisterLuaCoreEaseInOutAuto(lua);
RegisterLuaCoreEaseElasticAuto(lua);
RegisterLuaCoreEaseElasticInAuto(lua);
RegisterLuaCoreEaseElasticOutAuto(lua);
RegisterLuaCoreEaseElasticInOutAuto(lua);
RegisterLuaCoreEaseBezierActionAuto(lua);
RegisterLuaCoreActionInstantAuto(lua);
RegisterLuaCoreShowAuto(lua);
RegisterLuaCoreHideAuto(lua);
RegisterLuaCoreToggleVisibilityAuto(lua);
RegisterLuaCoreRemoveSelfAuto(lua);
RegisterLuaCoreFlipXAuto(lua);
RegisterLuaCoreFlipYAuto(lua);
RegisterLuaCorePlaceAuto(lua);
RegisterLuaCoreCallFuncAuto(lua);
RegisterLuaCoreGridActionAuto(lua);
RegisterLuaCoreGrid3DActionAuto(lua);
RegisterLuaCoreTiledGrid3DActionAuto(lua);
RegisterLuaCoreStopGridAuto(lua);
RegisterLuaCoreReuseGridAuto(lua);
RegisterLuaCoreWaves3DAuto(lua);
RegisterLuaCoreFlipX3DAuto(lua);
RegisterLuaCoreFlipY3DAuto(lua);
RegisterLuaCoreLens3DAuto(lua);
RegisterLuaCoreRipple3DAuto(lua);
RegisterLuaCoreShaky3DAuto(lua);
RegisterLuaCoreLiquidAuto(lua);
RegisterLuaCoreWavesAuto(lua);
RegisterLuaCoreTwirlAuto(lua);
RegisterLuaCoreActionManagerAuto(lua);
RegisterLuaCoreProgressToAuto(lua);
RegisterLuaCoreProgressFromToAuto(lua);
RegisterLuaCoreShuffleTilesAuto(lua);
RegisterLuaCoreFadeOutTRTilesAuto(lua);
RegisterLuaCoreFadeOutBLTilesAuto(lua);
RegisterLuaCoreFadeOutUpTilesAuto(lua);
RegisterLuaCoreFadeOutDownTilesAuto(lua);
RegisterLuaCoreTurnOffTilesAuto(lua);
RegisterLuaCoreWavesTiles3DAuto(lua);
RegisterLuaCoreJumpTiles3DAuto(lua);
RegisterLuaCoreSplitRowsAuto(lua);
RegisterLuaCoreSplitColsAuto(lua);
RegisterLuaCoreActionTweenDelegateAuto(lua);
RegisterLuaCoreActionTweenAuto(lua);
RegisterLuaCoreAtlasNodeAuto(lua);
RegisterLuaCoreClippingNodeAuto(lua);
RegisterLuaCoreClippingRectangleNodeAuto(lua);
RegisterLuaCoreDrawNodeAuto(lua);
RegisterLuaCoreLabelAuto(lua);
RegisterLuaCoreLabelAtlasAuto(lua);
RegisterLuaCoreTouchAuto(lua);
RegisterLuaCoreLayerAuto(lua);
RegisterLuaCoreLayerColorAuto(lua);
RegisterLuaCoreLayerGradientAuto(lua);
RegisterLuaCoreLayerRadialGradientAuto(lua);
RegisterLuaCoreLayerMultiplexAuto(lua);
RegisterLuaCoreMenuItemAuto(lua);
RegisterLuaCoreMenuItemLabelAuto(lua);
RegisterLuaCoreMenuItemAtlasFontAuto(lua);
RegisterLuaCoreMenuItemFontAuto(lua);
RegisterLuaCoreMenuItemSpriteAuto(lua);
RegisterLuaCoreMenuItemImageAuto(lua);
RegisterLuaCoreMenuItemToggleAuto(lua);
RegisterLuaCoreMenuAuto(lua);
RegisterLuaCoreMotionStreakAuto(lua);
RegisterLuaCoreNodeGridAuto(lua);
RegisterLuaCoreParticleBatchNodeAuto(lua);
RegisterLuaCoreParticleSystemAuto(lua);
RegisterLuaCoreParticleSystemQuadAuto(lua);
RegisterLuaCoreParticleFireAuto(lua);
RegisterLuaCoreParticleFireworksAuto(lua);
RegisterLuaCoreParticleSunAuto(lua);
RegisterLuaCoreParticleGalaxyAuto(lua);
RegisterLuaCoreParticleFlowerAuto(lua);
RegisterLuaCoreParticleMeteorAuto(lua);
RegisterLuaCoreParticleSpiralAuto(lua);
RegisterLuaCoreParticleExplosionAuto(lua);
RegisterLuaCoreParticleSmokeAuto(lua);
RegisterLuaCoreParticleSnowAuto(lua);
RegisterLuaCoreParticleRainAuto(lua);
RegisterLuaCoreProgressTimerAuto(lua);
RegisterLuaCoreProtectedNodeAuto(lua);
RegisterLuaCoreSpriteAuto(lua);
RegisterLuaCoreRenderTextureAuto(lua);
RegisterLuaCoreTransitionEaseSceneAuto(lua);
RegisterLuaCoreTransitionSceneAuto(lua);
RegisterLuaCoreTransitionSceneOrientedAuto(lua);
RegisterLuaCoreTransitionRotoZoomAuto(lua);
RegisterLuaCoreTransitionJumpZoomAuto(lua);
RegisterLuaCoreTransitionMoveInLAuto(lua);
RegisterLuaCoreTransitionMoveInRAuto(lua);
RegisterLuaCoreTransitionMoveInTAuto(lua);
RegisterLuaCoreTransitionMoveInBAuto(lua);
RegisterLuaCoreTransitionSlideInLAuto(lua);
RegisterLuaCoreTransitionSlideInRAuto(lua);
RegisterLuaCoreTransitionSlideInBAuto(lua);
RegisterLuaCoreTransitionSlideInTAuto(lua);
RegisterLuaCoreTransitionShrinkGrowAuto(lua);
RegisterLuaCoreTransitionFlipXAuto(lua);
RegisterLuaCoreTransitionFlipYAuto(lua);
RegisterLuaCoreTransitionFlipAngularAuto(lua);
RegisterLuaCoreTransitionZoomFlipXAuto(lua);
RegisterLuaCoreTransitionZoomFlipYAuto(lua);
RegisterLuaCoreTransitionZoomFlipAngularAuto(lua);
RegisterLuaCoreTransitionFadeAuto(lua);
RegisterLuaCoreTransitionCrossFadeAuto(lua);
RegisterLuaCoreTransitionTurnOffTilesAuto(lua);
RegisterLuaCoreTransitionSplitColsAuto(lua);
RegisterLuaCoreTransitionSplitRowsAuto(lua);
RegisterLuaCoreTransitionFadeTRAuto(lua);
RegisterLuaCoreTransitionFadeBLAuto(lua);
RegisterLuaCoreTransitionFadeUpAuto(lua);
RegisterLuaCoreTransitionFadeDownAuto(lua);
RegisterLuaCoreTransitionPageTurnAuto(lua);
RegisterLuaCoreTransitionProgressAuto(lua);
RegisterLuaCoreTransitionProgressRadialCCWAuto(lua);
RegisterLuaCoreTransitionProgressRadialCWAuto(lua);
RegisterLuaCoreTransitionProgressHorizontalAuto(lua);
RegisterLuaCoreTransitionProgressVerticalAuto(lua);
RegisterLuaCoreTransitionProgressInOutAuto(lua);
RegisterLuaCoreTransitionProgressOutInAuto(lua);
RegisterLuaCoreCameraFlagAuto(lua);
RegisterLuaCoreCameraAuto(lua);
RegisterLuaCoreCameraBackgroundBrushAuto(lua);
RegisterLuaCoreCameraBackgroundDepthBrushAuto(lua);
RegisterLuaCoreCameraBackgroundColorBrushAuto(lua);
RegisterLuaCoreCameraBackgroundSkyBoxBrushAuto(lua);
RegisterLuaCoreGridBaseAuto(lua);
RegisterLuaCoreGrid3DAuto(lua);
RegisterLuaCoreLightTypeAuto(lua);
RegisterLuaCoreLightFlagAuto(lua);
RegisterLuaCoreBaseLightAuto(lua);
RegisterLuaCoreDirectionLightAuto(lua);
RegisterLuaCorePointLightAuto(lua);
RegisterLuaCoreSpotLightAuto(lua);
RegisterLuaCoreAmbientLightAuto(lua);
RegisterLuaCoreRenderStateAuto(lua);
RegisterLuaCoreTechniqueAuto(lua);
RegisterLuaCoreMaterialAuto(lua);
RegisterLuaCorePassAuto(lua);
RegisterLuaCoreRendererAuto(lua);
RegisterLuaCoreTextureCacheAuto(lua);
RegisterLuaCoreDeviceAuto(lua);
RegisterLuaCoreApplicationProtocolAuto(lua);
RegisterLuaCoreApplicationAuto(lua);
RegisterLuaCoreGLViewImplAuto(lua);
RegisterLuaCoreAnimationCacheAuto(lua);
RegisterLuaCoreSpriteBatchNodeAuto(lua);
RegisterLuaCoreSpriteFrameCacheAuto(lua);
RegisterLuaCoreParallaxNodeAuto(lua);
RegisterLuaCoreTMXObjectGroupAuto(lua);
RegisterLuaCoreTMXTileFlags_Auto(lua);
RegisterLuaCoreTMXLayerInfoAuto(lua);
RegisterLuaCoreTMXTilesetInfoAuto(lua);
RegisterLuaCoreTMXMapInfoAuto(lua);
RegisterLuaCoreTileMapAtlasAuto(lua);
RegisterLuaCoreFastTMXLayerAuto(lua);
RegisterLuaCoreTMXTileAnimTaskAuto(lua);
RegisterLuaCoreTMXTileAnimManagerAuto(lua);
RegisterLuaCoreFastTMXTiledMapAuto(lua);
RegisterLuaCoreCryptoAuto(lua);
RegisterLuaCoreConnectionAuto(lua);
RegisterLuaCoreServerAuto(lua);
RegisterLuaCoreClientAuto(lua);
RegisterLuaCoreDownloadTaskAuto(lua);
RegisterLuaCoreDownloaderAuto(lua);
}
}