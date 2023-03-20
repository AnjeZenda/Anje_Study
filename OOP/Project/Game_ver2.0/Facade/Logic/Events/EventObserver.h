#ifndef GAME_VER2_0_EVENTOBSERVER_H
#define GAME_VER2_0_EVENTOBSERVER_H


#include "ExitEvent.h"
#include "PlayerEvent/DamageCurseEvent.h"
#include "PlayerEvent/CurseEvent.h"
#include "PlayerEvent/ManaEvent.h"
#include "PlayerEvent/HealEvent.h"
#include "FieldEvent/ChangePassability.h"
#include "FieldEvent/ReverseField.h"

class EventObserver
        : public IExitEventObserver,
          public IDamageCurseEventObserver,
          public ICurseEventObserver,
          public IManaEventObserver,
          public IHealthEventObserver,
          public IChangePassabilityEventObserver,
          public IReverseFieldEventObserver{
public:
    void onExitEventInvoked() override;
    void onDamageCurseEventInvoked(int damage) override;
    void onCurseEventInvoked() override;
    void onHealthEventInvoked() override;
    void onManaEventInvoked() override;
    void onChangePassabilityEventInvoked() override;
    void onReverseFieldEventInvoked() override;
};


#endif //GAME_VER2_0_EVENTOBSERVER_H