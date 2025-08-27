#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int MaxHP = health;
    int HealTime = bandage[0];
    int HealPerSec = bandage[1];
    int ExtraHeal = bandage[2];
    int SuccessTime = 0;
    int attacked = 0;

    for (int i = 1; i <= attacks[attacks.size() - 1][0]; i++) {

        for (int j = 0; j < attacks.size(); j++)
        {
            if (attacks[j][0] == i)
            {
                health -= attacks[j][1];
                SuccessTime = 1;
                attacked = 1;
            }
        }

        if (health <= 0)
        {
            return -1;
        }

        if (attacked == 0 && HealTime != 1)
        {
            if ((MaxHP - health) >= HealPerSec)
            {
                if (SuccessTime != HealTime)
                {
                    health += HealPerSec;
                    SuccessTime += 1;
                }
                else if (SuccessTime == HealTime && (MaxHP - health) >= HealPerSec + ExtraHeal)
                {
                    health += HealPerSec + ExtraHeal;
                    SuccessTime = 1;
                }
                else if (SuccessTime == HealTime && (MaxHP - health) < HealPerSec + ExtraHeal)
                {
                    health = MaxHP;
                    SuccessTime = 1;
                }
            }
            else if (MaxHP != health && (MaxHP - health) < HealPerSec)
            {
                if (SuccessTime != HealTime)
                {
                    health = MaxHP;
                    SuccessTime += 1;
                }
                else if (SuccessTime == HealTime)
                {
                    health = MaxHP;
                    SuccessTime = 1;
                }
            }
        }
        else if (attacked == 0 && HealTime == 1)
        {
            if ((MaxHP - health) >= HealPerSec + ExtraHeal)
            {
                health += (HealPerSec + ExtraHeal);
            }
            else if ((MaxHP - health) < HealPerSec + ExtraHeal)
            {
                health = MaxHP;
            }
        }

        attacked = 0;
    }

    return health;
}
