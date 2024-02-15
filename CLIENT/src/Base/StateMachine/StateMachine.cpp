#include "StateMachine.hpp"
#include "../State/State.hpp"

#include "../Hero/Hero.hpp"

#include "../IdleState/IdleState.hpp"
#include "../RunState/RunState.hpp"
#include "../JumpState/JumpState.hpp"
#include "../FallingState/FallingState.hpp"
#include "../AttackState/AttackState.hpp"

#include <cstring>

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
    if (_currentState != nullptr)
    {
        delete _currentState;
    }
}

void StateMachine::setState(State *newState, Hero &player)
{

    if (_currentState != nullptr)
    {
        _currentState->exitState(player);

        delete _currentState;
    }

    _currentState = newState;
    _Estate = newState->_tag;

    _currentState->enterState(player);
}

void StateMachine::restore_state(eMachineStates state, int tick)
{
    if (_Estate != (int)state)
    {
        if (_currentState != nullptr)
        {
            delete _currentState;
        }

        _Estate = (int)state;

        switch (state)
        {
        case eIdleState:
            _currentState = new IdleState();
            break;

        case eRunState:
            _currentState = new RunState();
            break;

        case eJumpState:
            _currentState = new JumpState();
            break;

        case eFallingState:
            _currentState = new FallingState();
            break;

        case eAttack1State:
            _currentState = new AttackState();
            break;

        default:
            _currentState = nullptr;
            break;
        }
    }
}

void StateMachine::update(Hero &player)
{
    _currentState->update(player, _stateTick);
}
