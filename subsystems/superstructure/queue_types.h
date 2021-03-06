#ifndef C2017_SUBSYSTEMS_SUPERSTRUCTURE_QUEUE_TYPES_H_
#define C2017_SUBSYSTEMS_SUPERSTRUCTURE_QUEUE_TYPES_H_

#include "c2017/subsystems/superstructure/intake_group.pb.h"
#include "c2017/subsystems/superstructure/shooter_group.pb.h"
#include "c2017/subsystems/superstructure/superstructure.pb.h"
#include "muan/proto/stack_proto.h"
#include "muan/queues/message_queue.h"

namespace c2017 {

namespace intake_group {

using IntakeGroupGoalProto = muan::proto::StackProto<IntakeGroupGoal, 256>;

using IntakeGroupGoalQueue = muan::queues::MessageQueue<IntakeGroupGoalProto>;

}  // namespace intake_group

namespace shooter_group {

using ShooterGroupGoalProto =
    muan::proto::StackProto<::c2017::shooter_group::ShooterGroupGoal, 256>;

using ShooterGroupGoalQueue = muan::queues::MessageQueue<ShooterGroupGoalProto>;

}  // namespace shooter_group

namespace superstructure {
using SuperstructureStatusProto =
    muan::proto::StackProto<SuperstructureStatus, 256>;

using SuperstructureStatusQueue =
    muan::queues::MessageQueue<SuperstructureStatusProto>;
}  // namespace superstructure

}  // namespace c2017

#endif  // C2017_SUBSYSTEMS_SUPERSTRUCTURE_QUEUE_TYPES_H_
