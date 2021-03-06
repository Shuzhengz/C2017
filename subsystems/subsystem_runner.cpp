#include "c2017/subsystems/subsystem_runner.h"
#include "muan/utils/threading_utils.h"

namespace c2017 {

SubsystemRunner::SubsystemRunner()
    : drivetrain_{::c2017::drivetrain::GetDrivetrainConfig(),
                  QueueManager::GetInstance()->drivetrain_goal_queue(),
                  QueueManager::GetInstance()->drivetrain_input_queue(),
                  QueueManager::GetInstance()->drivetrain_output_queue(),
                  QueueManager::GetInstance()->drivetrain_status_queue(),
                  QueueManager::GetInstance()->driver_station_queue(),
                  QueueManager::GetInstance()->gyro_queue()},
      superstructure_{},
      vision_{} {}

void SubsystemRunner::operator()() {
  aos::time::PhasedLoop phased_loop(std::chrono::milliseconds(5));

  // TODO(Kyle or Wesley) Come up with some actual value for this...
  aos::SetCurrentThreadRealtimePriority(50);
  muan::utils::SetCurrentThreadName("SubsystemRunner");

  running_ = true;

  while (running_) {
    wpilib_.ReadSensors();

    drivetrain_.Update();

    superstructure_.Update();

    lights_.Update();

    vision_.Update();

    wpilib_.WriteActuators();

    phased_loop.SleepUntilNext();
  }
}

void SubsystemRunner::Stop() { running_ = false; }

}  // namespace c2017
