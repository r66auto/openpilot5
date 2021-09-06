#pragma once

#include <QPushButton>
#include <QSoundEffect>

#include "selfdrive/hardware/hw.h"
#include "selfdrive/ui/qt/widgets/controls.h"
#include "selfdrive/ui/ui.h"
#include <QComboBox>
#include <QAbstractItemView>

class SwitchOpenpilot : public ButtonControl {
  Q_OBJECT

public:
  SwitchOpenpilot();

private:
  Params params;

  QString githubid;
  QString githubrepo;
  QString githubbranch;

  void refresh();
  void getUserID(const QString &userid);
  void getRepoID(const QString &repoid);
  void getBranchID(const QString &branchid);
};

class SshLegacyToggle : public ToggleControl {
  Q_OBJECT

public:
  SshLegacyToggle() : ToggleControl("Use Existing Public Key", "When connecting via SSH, the existing public key (0.8.2 or lower) is used.", "", Params().getBool("OpkrSSHLegacy")) {
    QObject::connect(this, &SshLegacyToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrSSHLegacy", status);
    });
  }
};

class GetoffAlertToggle : public ToggleControl {
  Q_OBJECT

public:
  GetoffAlertToggle() : ToggleControl("Enable Device Notification After Get Off", "Send a notification to disconnect the device after get off.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrEnableGetoffAlert")) {
    QObject::connect(this, &GetoffAlertToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrEnableGetoffAlert", status);
    });
  }
};

class AutoResumeToggle : public ToggleControl {
  Q_OBJECT

public:
  AutoResumeToggle() : ToggleControl("Enable Auto Resume", "Auto Resume is used when stopping while using SCC.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrAutoResume")) {
    QObject::connect(this, &AutoResumeToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrAutoResume", status);
    });
  }
};

class VariableCruiseToggle : public ToggleControl {
  Q_OBJECT

public:
  VariableCruiseToggle() : ToggleControl("Enable Variable Cruise", "Acceleration/deceleration is supported by using the cruise button while SCC is in use.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrVariableCruise")) {
    QObject::connect(this, &VariableCruiseToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrVariableCruise", status);
    });
  }
};

class CruiseGapAdjustToggle : public ToggleControl {
  Q_OBJECT

public:
  CruiseGapAdjustToggle() : ToggleControl("Auto Set Cruise Cap When Stopped", "When stopping, the cruise gap is changed to 1 space for a quick departure. After moving from standstill, it returns to the original cruise gap according to certain conditions.", "../assets/offroad/icon_shell.png", Params().getBool("CruiseGapAdjust")) {
    QObject::connect(this, &CruiseGapAdjustToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("CruiseGapAdjust", status);
    });
  }
};

class AutoEnabledToggle : public ToggleControl {
  Q_OBJECT

public:
  AutoEnabledToggle() : ToggleControl("Enable Auto Engage", "When disengaged, if the cruise button is in the standby state (only CRUISE is displayed and the speed is not specified), auto engage is activated.", "../assets/offroad/icon_shell.png", Params().getBool("AutoEnable")) {
    QObject::connect(this, &AutoEnabledToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("AutoEnable", status);
    });
  }
};

class CruiseAutoResToggle : public ToggleControl {
  Q_OBJECT

public:
  CruiseAutoResToggle() : ToggleControl("Enable Cruise Auto RES", "If brake is pressed and disengages cruise (CANCEL button not applicable), when the brake pedal is released/the gas pedal pedal is pressed, the previous set speed is set. Cruise Auto RES is enabled when cruise speed is over 30km/h or a car is recognized at the front.", "../assets/offroad/icon_shell.png", Params().getBool("CruiseAutoRes")) {
    QObject::connect(this, &CruiseAutoResToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("CruiseAutoRes", status);
    });
  }
};

class BatteryChargingControlToggle : public ToggleControl {
  Q_OBJECT

public:
  BatteryChargingControlToggle() : ToggleControl("Enable Battery Charging Control", "Enables battery charging control.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrBatteryChargingControl")) {
    QObject::connect(this, &BatteryChargingControlToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrBatteryChargingControl", status);
    });
  }
};

class BlindSpotDetectToggle : public ToggleControl {
  Q_OBJECT

public:
  BlindSpotDetectToggle() : ToggleControl("Display Blind Spot Detection Icon", "When a car is detected at your blind spot, an icon is displayed on the screen.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrBlindSpotDetect")) {
    QObject::connect(this, &BlindSpotDetectToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrBlindSpotDetect", status);
      if (state) {
        QUIState::ui_state.scene.nOpkrBlindSpotDetect = true;
      } else {
        QUIState::ui_state.scene.nOpkrBlindSpotDetect = false;
      }
    });
  }
};

class MadModeEnabledToggle : public ToggleControl {
  Q_OBJECT

public:
  MadModeEnabledToggle() : ToggleControl("ACC MAIN openpilot ON/OFF", "Use ACC MAIN to activate openpilot.", "../assets/offroad/icon_shell.png", Params().getBool("MadModeEnabled")) {
    QObject::connect(this, &MadModeEnabledToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("MadModeEnabled", status);
    });
  }
};

class WhitePandaSupportToggle : public ToggleControl {
  Q_OBJECT

public:
  WhitePandaSupportToggle() : ToggleControl("White Panda Support", "Turn on the feature when using White Panda", "../assets/offroad/icon_shell.png", Params().getBool("WhitePandaSupport")) {
    QObject::connect(this, &WhitePandaSupportToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("WhitePandaSupport", status);
    });
  }
};

class SteerWarningFixToggle : public ToggleControl {
  Q_OBJECT

public:
  SteerWarningFixToggle() : ToggleControl("Turn Off Steering Warning", "Turn on the feature when the vehicle has a steering error that makes it impossible to steer (only for some cars). Do not turn on the feature when it occurs in a normal error environment while driving.", "../assets/offroad/icon_shell.png", Params().getBool("SteerWarningFix")) {
    QObject::connect(this, &SteerWarningFixToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("SteerWarningFix", status);
    });
  }
};

class SteerWindDownToggle : public ToggleControl {
  Q_OBJECT

public:
  SteerWindDownToggle() : ToggleControl("Steer Wind Down", "During Steer Warning, the torque is gradually reduced. In some vehicles, the steering angle limit light may appear. Turn off the feature to use the maximum steering angle regardless of the error.", "../assets/offroad/icon_shell.png", Params().getBool("SteerWindDown")) {
    QObject::connect(this, &SteerWindDownToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("SteerWindDown", status);
    });
  }
};

class AutoScreenDimmingToggle : public ToggleControl {
  Q_OBJECT

public:
  AutoScreenDimmingToggle() : ToggleControl("Auto Screen Dimming Control", "By maintaining the minimum brightness while driving, it reduces battery consumption and heat generation, and increases the brightness when an event occurs to temporarily secure visibility.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrAutoScreenDimming")) {
    QObject::connect(this, &AutoScreenDimmingToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrAutoScreenDimming", status);
    });
  }
};

class LiveSteerRatioToggle : public ToggleControl {
  Q_OBJECT

public:
  LiveSteerRatioToggle() : ToggleControl("Enable Live SteerRatio", "Enables Live SteerRatio instead of variable/fixed SteerRatio.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrLiveSteerRatio")) {
    QObject::connect(this, &LiveSteerRatioToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrLiveSteerRatio", status);
    });
  }
};

class VariableSteerMaxToggle : public ToggleControl {
  Q_OBJECT

public:
  VariableSteerMaxToggle() : ToggleControl("Enable Variable SteerMax", "Enable variable SteerMax based on curvature.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrVariableSteerMax")) {
    QObject::connect(this, &VariableSteerMaxToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrVariableSteerMax", status);
    });
  }
};

class VariableSteerDeltaToggle : public ToggleControl {
  Q_OBJECT

public:
  VariableSteerDeltaToggle() : ToggleControl("Enable Variable SteerDelta", "Enable variable SteerDelta based on curvature (change from DeltaUp to 5, change from DeltaDown to 10).", "../assets/offroad/icon_shell.png", Params().getBool("OpkrVariableSteerDelta")) {
    QObject::connect(this, &VariableSteerDeltaToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrVariableSteerDelta", status);
    });
  }
};

class ShaneFeedForward : public ToggleControl {
  Q_OBJECT

public:
  ShaneFeedForward() : ToggleControl("Enable Shane FeedForward", "Enables Shane's FeedForward. Depending on the steering angle, torque is lowered on straight roads and dynamically adjusted on curved roads.", "../assets/offroad/icon_shell.png", Params().getBool("ShaneFeedForward")) {
    QObject::connect(this, &ShaneFeedForward::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("ShaneFeedForward", status);
    });
  }
};

class DrivingRecordToggle : public ToggleControl {
  Q_OBJECT

public:
  DrivingRecordToggle() : ToggleControl("Enable Auto Recording", "Automatically record/stop the screen while driving. Recording starts after departure and ends when the car stops.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrDrivingRecord")) {
    QObject::connect(this, &DrivingRecordToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrDrivingRecord", status);
      if (state) {
        QUIState::ui_state.scene.driving_record = true;
      } else {
        QUIState::ui_state.scene.driving_record = false;
      }
    });
  }
};

class TurnSteeringDisableToggle : public ToggleControl {
  Q_OBJECT

public:
  TurnSteeringDisableToggle() : ToggleControl("Enable Autosteer Suspension", "When turn signal is used below the lane change speed, autosteer is temporary suspended.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrTurnSteeringDisable")) {
    QObject::connect(this, &TurnSteeringDisableToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrTurnSteeringDisable", status);
    });
  }
};

class HotspotOnBootToggle : public ToggleControl {
  Q_OBJECT

public:
  HotspotOnBootToggle() : ToggleControl("Auto Launch Hotspot on Boot", "Automatically launch hotspot after booting.", "", Params().getBool("OpkrHotspotOnBoot")) {
    QObject::connect(this, &HotspotOnBootToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrHotspotOnBoot", status);
    });
  }
};

class CruiseOverMaxSpeedToggle : public ToggleControl {
  Q_OBJECT

public:
  CruiseOverMaxSpeedToggle() : ToggleControl("Set Cruise Over Max Speed", "If the current speed exceeds the set speed, the set speed is synchronized with the current speed.", "../assets/offroad/icon_shell.png", Params().getBool("CruiseOverMaxSpeed")) {
    QObject::connect(this, &CruiseOverMaxSpeedToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("CruiseOverMaxSpeed", status);
    });
  }
};

class DebugUiOneToggle : public ToggleControl {
  Q_OBJECT

public:
  DebugUiOneToggle() : ToggleControl("DEBUG UI 1", "", "../assets/offroad/icon_shell.png", Params().getBool("DebugUi1")) {
    QObject::connect(this, &DebugUiOneToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("DebugUi1", status);
      if (state) {
        QUIState::ui_state.scene.nDebugUi1 = true;
      } else {
        QUIState::ui_state.scene.nDebugUi1 = false;
      }
    });
  }
};

class DebugUiTwoToggle : public ToggleControl {
  Q_OBJECT

public:
  DebugUiTwoToggle() : ToggleControl("DEBUG UI 2", "", "../assets/offroad/icon_shell.png", Params().getBool("DebugUi2")) {
    QObject::connect(this, &DebugUiTwoToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("DebugUi2", status);
      if (state) {
        QUIState::ui_state.scene.nDebugUi2 = true;
      } else {
        QUIState::ui_state.scene.nDebugUi2 = false;
      }
    });
  }
};

class LongLogToggle : public ToggleControl {
  Q_OBJECT

public:
  LongLogToggle() : ToggleControl("LONG LOG View", "Instead of the variable cruise log, the long tuning debug log is displayed on the screen.", "../assets/offroad/icon_shell.png", Params().getBool("LongLogDisplay")) {
    QObject::connect(this, &LongLogToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("LongLogDisplay", status);
    });
  }
};

class PrebuiltToggle : public ToggleControl {
  Q_OBJECT

public:
  PrebuiltToggle() : ToggleControl("Create Prebuilt File", "Shortens the boot time by creating a prebuilt file. If you have made UI modifications, turn off the feature temporarily.", "../assets/offroad/icon_shell.png", Params().getBool("PutPrebuiltOn")) {
    QObject::connect(this, &PrebuiltToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("PutPrebuiltOn", status);
    });
  }
};

class LDWSToggle : public ToggleControl {
  Q_OBJECT

public:
  LDWSToggle() : ToggleControl("LDWS Car Settings", "", "../assets/offroad/icon_shell.png", Params().getBool("LdwsCarFix")) {
    QObject::connect(this, &LDWSToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("LdwsCarFix", status);
    });
  }
};

class FPTwoToggle : public ToggleControl {
  Q_OBJECT

public:
  FPTwoToggle() : ToggleControl("Enable FingerPrint 2.0", "Enable Fingerprint 2.0. The car is recognized by ECU firmware recognition.", "../assets/offroad/icon_shell.png", Params().getBool("FingerprintTwoSet")) {
    QObject::connect(this, &FPTwoToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("FingerprintTwoSet", status);
    });
  }
};

class GearDToggle : public ToggleControl {
  Q_OBJECT

public:
  GearDToggle() : ToggleControl("Gear D Force Recognition", "For use when engagement is not possible due to a gear recognition problem. It is fundamentally necessary to analyze CABANA data, but it is a temporary solution.", "../assets/offroad/icon_shell.png", Params().getBool("JustDoGearD")) {
    QObject::connect(this, &GearDToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("JustDoGearD", status);
    });
  }
};

class ComIssueToggle : public ToggleControl {
  Q_OBJECT

public:
  ComIssueToggle() : ToggleControl("Turn off ComIssue", "Turn on this feature to turn off Communication Error Between Processes alarm when using White Panda.", "../assets/offroad/icon_shell.png", Params().getBool("ComIssueGone")) {
    QObject::connect(this, &ComIssueToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("ComIssueGone", status);
    });
  }
};

class RunNaviOnBootToggle : public ToggleControl {
  Q_OBJECT

public:
  RunNaviOnBootToggle() : ToggleControl("Navi Auto Launch On Boot", "After booting, navigation (T Map) is automatically launched.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrRunNaviOnBoot")) {
    QObject::connect(this, &RunNaviOnBootToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrRunNaviOnBoot", status);
    });
  }
};

class BattLessToggle : public ToggleControl {
  Q_OBJECT

public:
  BattLessToggle() : ToggleControl("Use Batteryless", "Toggle for batteryless device. Relevant settings will be applied.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrBattLess")) {
    QObject::connect(this, &BattLessToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrBattLess", status);
    });
  }
};

class LiveTunePanelToggle : public ToggleControl {
  Q_OBJECT

public:
  LiveTunePanelToggle() : ToggleControl("Enable LiveTune and UI", "Display the Live Tune UI. Tuning values can be set in realtime on the onroad screen. The adjustments are set in the parameters, values are maintained even after a reboot or the toggle is turned off.", "../assets/offroad/icon_shell.png", Params().getBool("OpkrLiveTunePanelEnable")) {
    QObject::connect(this, &LiveTunePanelToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("OpkrLiveTunePanelEnable", status);
      if (state) {
        QUIState::ui_state.scene.live_tune_panel_enable = true;
        QUIState::ui_state.scene.opkr_livetune_ui = true;
      } else {
        QUIState::ui_state.scene.live_tune_panel_enable = false;
        QUIState::ui_state.scene.opkr_livetune_ui = false;
      }
    });
  }
};

class KRDateToggle : public ToggleControl {
  Q_OBJECT

public:
  KRDateToggle() : ToggleControl("Onroad Date Display", "Display the current date on the onroad screen.", "../assets/offroad/icon_shell.png", Params().getBool("KRDateShow")) {
    QObject::connect(this, &KRDateToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("KRDateShow", status);
      if (state) {
        QUIState::ui_state.scene.kr_date_show = true;
      } else {
        QUIState::ui_state.scene.kr_date_show = false;
      }
    });
  }
};

class KRTimeToggle : public ToggleControl {
  Q_OBJECT

public:
  KRTimeToggle() : ToggleControl("Onroad Time Display", "Display the current time on the onroad screen.", "../assets/offroad/icon_shell.png", Params().getBool("KRTimeShow")) {
    QObject::connect(this, &KRTimeToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("KRTimeShow", status);
      if (state) {
        QUIState::ui_state.scene.kr_time_show = true;
      } else {
        QUIState::ui_state.scene.kr_time_show = false;
      }
    });
  }
};

class LeadCustomToggle : public ToggleControl {
  Q_OBJECT

public:
  LeadCustomToggle() : ToggleControl("Display Preceding Vehicle", "Display the custom image of the preceding vehicle on the onroad screen.", "../assets/offroad/icon_shell.png", Params().getBool("LeadCustom")) {
    QObject::connect(this, &LeadCustomToggle::toggleFlipped, [=](int state) {
      char status = state ? true : false;
      Params().putBool("LeadCustom", status);
    });
  }
};

class RadarLongHelperToggle : public ToggleControl {
  Q_OBJECT

public:
  RadarLongHelperToggle() : ToggleControl("Enable Radar Long Assist", "When VOACC, radar value + comma vision long (interpolation) is used at close range (less than 25m). In situations where VOACC cannot stop sufficiently, it uses radar values to make sure the car stops. The feature is used only when the radar recognizes the car in front. When the car in front is not recognized (green chevron), the car is decelerated only with comma visoin long. When this feature is off, it means to always use comma vision long.", "../assets/offroad/icon_shell.png", Params().getBool("RadarLongHelper")) {
    QObject::connect(this, &RadarLongHelperToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("RadarLongHelper", status);
    });
  }
};

class FCATypeToggle : public ToggleControl {
  Q_OBJECT

public:
  FCATypeToggle() : ToggleControl("Enable FCA11", "FCA11 is used instead of SCC12 for forward collision warnings. It is used when a forward collision error occurs during engage or boot. Please note that a car without the signal may cause a CAN error.", "../assets/offroad/icon_shell.png", Params().getBool("FCAType")) {
    QObject::connect(this, &FCATypeToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("FCAType", status);
    });
  }
};

class GitPullOnBootToggle : public ToggleControl {
  Q_OBJECT

public:
  GitPullOnBootToggle() : ToggleControl("Auto Git Pull at Boot", "If there is an update after booting, Git Pull is automatically executed and rebooted.", "", Params().getBool("GitPullOnBoot")) {
    QObject::connect(this, &GitPullOnBootToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("GitPullOnBoot", status);
    });
  }
};

class StoppingDistAdjToggle : public ToggleControl {
  Q_OBJECT

public:
  StoppingDistAdjToggle() : ToggleControl("Set Stopping Distance", "The car stops slightly ahead of the radar stopping distance. Some rattles may occur, so if you are uncomfortable, disable this feature.", "", Params().getBool("StoppingDistAdj")) {
    QObject::connect(this, &StoppingDistAdjToggle::toggleFlipped, [=](int state) {
      bool status = state ? true : false;
      Params().putBool("StoppingDistAdj", status);
    });
  }
};

// openpilot Preview
class OpenpilotView : public AbstractControl {
  Q_OBJECT

public:
  OpenpilotView();

private:
  QPushButton btn;
  Params params;
  
  void refresh();
};

// Force Car Recognition
class CarRecognition : public AbstractControl {
  Q_OBJECT

public:
  CarRecognition();

private:
  QPushButton btn;
  QString carname;
  QLabel carname_label;
  Params params;
  
  void refresh(QString carname);
};

class CarSelectCombo : public AbstractControl 
{
  Q_OBJECT

public:
  CarSelectCombo();

private:
  QPushButton btn;
  QComboBox combobox;
  Params params;

  void refresh();
};


// UI Settings
class AutoShutdown : public AbstractControl {
  Q_OBJECT

public:
  AutoShutdown();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class ForceShutdown : public AbstractControl {
  Q_OBJECT

public:
  ForceShutdown();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class AutoScreenOff : public AbstractControl {
  Q_OBJECT

public:
  AutoScreenOff();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class VolumeControl : public AbstractControl {
  Q_OBJECT

public:
  VolumeControl();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  QSoundEffect effect;
  
  void refresh();
  void playsound();
};

class BrightnessControl : public AbstractControl {
  Q_OBJECT

public:
  BrightnessControl();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class BrightnessOffControl : public AbstractControl {
  Q_OBJECT

public:
  BrightnessOffControl();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};


class ChargingMin : public AbstractControl {
  Q_OBJECT

public:
  ChargingMin();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};
class ChargingMax : public AbstractControl {
  Q_OBJECT

public:
  ChargingMax();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};


// Driving Settings
class CruisemodeSelInit : public AbstractControl {
  Q_OBJECT

public:
  CruisemodeSelInit();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class VariableCruiseProfile : public AbstractControl {
  Q_OBJECT

public:
  VariableCruiseProfile();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LaneChangeSpeed : public AbstractControl {
  Q_OBJECT

public:
  LaneChangeSpeed();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LaneChangeDelay : public AbstractControl {
  Q_OBJECT

public:
  LaneChangeDelay();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LeftCurvOffset : public AbstractControl {
  Q_OBJECT

public:
  LeftCurvOffset();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};
class RightCurvOffset : public AbstractControl {
  Q_OBJECT

public:
  RightCurvOffset();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MaxAngleLimit : public AbstractControl {
  Q_OBJECT

public:
  MaxAngleLimit();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SpeedLimitOffset : public AbstractControl {
  Q_OBJECT

public:
  SpeedLimitOffset();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

// Tuning Settings
class CameraOffset : public AbstractControl {
  Q_OBJECT

public:
  CameraOffset();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class PathOffset : public AbstractControl {
  Q_OBJECT

public:
  PathOffset();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SRBaseControl : public AbstractControl {
  Q_OBJECT

public:
  SRBaseControl();

private:
  QPushButton btndigit;
  QPushButton btnminus;
  QPushButton btnplus;
  QPushButton btndirect;
  QLabel label;
  Params params;
  float digit = 0.01;
  
  void refresh();
};
class SRMaxControl : public AbstractControl {
  Q_OBJECT

public:
  SRMaxControl();

private:
  QPushButton btndigit;
  QPushButton btnminus;
  QPushButton btnplus;
  QLabel label;
  Params params;
  float digit = 0.01;
  
  void refresh();
};

class SteerActuatorDelay : public AbstractControl {
  Q_OBJECT

public:
  SteerActuatorDelay();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerRateCost : public AbstractControl {
  Q_OBJECT

public:
  SteerRateCost();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerLimitTimer : public AbstractControl {
  Q_OBJECT

public:
  SteerLimitTimer();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class TireStiffnessFactor : public AbstractControl {
  Q_OBJECT

public:
  TireStiffnessFactor();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerMaxBase : public AbstractControl {
  Q_OBJECT

public:
  SteerMaxBase();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerMaxMax : public AbstractControl {
  Q_OBJECT

public:
  SteerMaxMax();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerMaxv : public AbstractControl {
  Q_OBJECT

public:
  SteerMaxv();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerDeltaUpBase : public AbstractControl {
  Q_OBJECT

public:
  SteerDeltaUpBase();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerDeltaUpMax : public AbstractControl {
  Q_OBJECT

public:
  SteerDeltaUpMax();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerDeltaDownBase : public AbstractControl {
  Q_OBJECT

public:
  SteerDeltaDownBase();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerDeltaDownMax : public AbstractControl {
  Q_OBJECT

public:
  SteerDeltaDownMax();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};


// Control Settings
class LateralControl : public AbstractControl {
  Q_OBJECT

public:
  LateralControl();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class PidKp : public AbstractControl {
  Q_OBJECT

public:
  PidKp();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class PidKi : public AbstractControl {
  Q_OBJECT

public:
  PidKi();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class PidKd : public AbstractControl {
  Q_OBJECT

public:
  PidKd();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class PidKf : public AbstractControl {
  Q_OBJECT

public:
  PidKf();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class IgnoreZone : public AbstractControl {
  Q_OBJECT

public:
  IgnoreZone();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class OuterLoopGain : public AbstractControl {
  Q_OBJECT

public:
  OuterLoopGain();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class InnerLoopGain : public AbstractControl {
  Q_OBJECT

public:
  InnerLoopGain();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class TimeConstant : public AbstractControl {
  Q_OBJECT

public:
  TimeConstant();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class ActuatorEffectiveness : public AbstractControl {
  Q_OBJECT

public:
  ActuatorEffectiveness();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class Scale : public AbstractControl {
  Q_OBJECT

public:
  Scale();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LqrKi : public AbstractControl {
  Q_OBJECT

public:
  LqrKi();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class DcGain : public AbstractControl {
  Q_OBJECT

public:
  DcGain();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerAngleCorrection : public AbstractControl {
  Q_OBJECT

public:
  SteerAngleCorrection();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MaxSteer : public AbstractControl {
  Q_OBJECT

public:
  MaxSteer();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MaxRTDelta : public AbstractControl {
  Q_OBJECT

public:
  MaxRTDelta();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MaxRateUp : public AbstractControl {
  Q_OBJECT

public:
  MaxRateUp();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MaxRateDown : public AbstractControl {
  Q_OBJECT

public:
  MaxRateDown();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class SteerThreshold : public AbstractControl {
  Q_OBJECT

public:
  SteerThreshold();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class RecordCount : public AbstractControl {
  Q_OBJECT

public:
  RecordCount();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class RecordQuality : public AbstractControl {
  Q_OBJECT

public:
  RecordQuality();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class GitHash : public AbstractControl {
  Q_OBJECT

public:
  GitHash();

private:
  QLabel local_hash;
  QLabel remote_hash;
  Params params;
};

class RESChoice : public AbstractControl {
  Q_OBJECT

public:
  RESChoice();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MonitoringMode : public AbstractControl {
  Q_OBJECT

public:
  MonitoringMode();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class MonitorEyesThreshold : public AbstractControl {
  Q_OBJECT

public:
  MonitorEyesThreshold();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class NormalEyesThreshold : public AbstractControl {
  Q_OBJECT

public:
  NormalEyesThreshold();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class BlinkThreshold : public AbstractControl {
  Q_OBJECT

public:
  BlinkThreshold();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class FanSpeedGain : public AbstractControl {
  Q_OBJECT

public:
  FanSpeedGain();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class CruiseGapTR : public AbstractControl {
  Q_OBJECT

public:
  CruiseGapTR();

private:
  QPushButton btn1;
  QPushButton btn2;
  QPushButton btn3;
  QPushButton btn4;
  QLabel label1;
  QLabel label2;
  QLabel label3;
  QLabel label4;
  QLabel label1a;
  QLabel label2a;
  QLabel label3a;
  QLabel label4a;
  Params params;
  
  void refresh1();
  void refresh2();
  void refresh3();
  void refresh4();
};

class DynamicTR : public AbstractControl {
  Q_OBJECT

public:
  DynamicTR();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LCTimingFactor : public AbstractControl {
  Q_OBJECT

public:
  LCTimingFactor();

private:
  QPushButton btn1;
  QPushButton btn2;
  QPushButton btn3;
  QPushButton btn4;
  QLabel label1;
  QLabel label2;
  QLabel label3;
  QLabel label4;
  QLabel label1a;
  QLabel label2a;
  QLabel label3a;
  QLabel label4a;
  Params params;

  void refresh1();
  void refresh2();
  void refresh3();
  void refresh4();
};

class LCTimingFactorUD : public AbstractControl {
  Q_OBJECT

public:
  LCTimingFactorUD();

private:
  QPushButton btn;
  QPushButton btn2;
  Params params;
  
  void refresh();
  void refresh2();
};

class AutoResCondition : public AbstractControl {
  Q_OBJECT

public:
  AutoResCondition();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class AutoEnableSpeed : public AbstractControl {
  Q_OBJECT

public:
  AutoEnableSpeed();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class CamDecelDistAdd : public AbstractControl {
  Q_OBJECT

public:
  CamDecelDistAdd();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};

class LiveSRPercent : public AbstractControl {
  Q_OBJECT

public:
  LiveSRPercent();

private:
  QPushButton btnplus;
  QPushButton btnminus;
  QLabel label;
  Params params;
  
  void refresh();
};