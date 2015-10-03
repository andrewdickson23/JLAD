/// \file

#include <string>
#include <iomanip>
#include <vector>
#include "../../include/Attachment.h"
using namespace std;

vector<attachment> initializeMembers() {
vector<attachment> attachments;
/// Delcares attachment objects 
attachment nunchucks;
attachment compshield;
attachment mushroom;
attachment mastersword;
attachment ring;
attachment force;
attachment mjolnir;
attachment elderwand;
attachment phaser;
attachment herb;
attachment capshield;
attachment batarang;
attachment rahgot;
attachment needler;
attachment maximmato;
attachment hpup;
attachment goldgun;
attachment chain;
attachment cherry;
attachment chaos;

string a = " ";


//ATTACHMENT TYPES - assigns attributes to each attachment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
nunchucks.name = "Nunchucks";
nunchucks.description = a+
   "Any Ninja-bot's best friend. Hand-crafted using the best available\n"+
   "stainless steel, with leather covered the handles for better grip.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |              ~  ~             |\n"+
   " |             )     )           |\n"+
   " |           ___     (           |\n"+
   " |          /  /      )          |\n"+
   " |         /--/      ___         |\n"+
   " |        /--/       \\  \\        |\n"+
   " |       /__/         \\--\\       |\n"+
   " |                     \\--\\      |\n"+
   " |                      \\__\\     |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +15\n"+
   " Speed:  +5\n"+
   " Weapon Range: 2\n"+
   " Weight:  +1 (-2 speed for every unit of weight encumbered)\n";

nunchucks.atkm = 15;
nunchucks.hpm = 0;
nunchucks.spdm = 5;
nunchucks.defm = 0;
nunchucks.rngm = 2;
nunchucks.weight = 1;
nunchucks.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compshield.name = "Companion Shield";
compshield.description = a+
   "Let's be honest, neither of us knows what this thing does. Just put it\n"+
   "in the corner and I'll deal with it later. - GLaDOS\n\n"+
   
   "  -------------------------------\n"+
   " |         ^----^^----^          |\n"+
   " |        /  /  ||  \\  \\         |\n"+
   " |       |  /  _||_  \\  |        |\n"+
   " |       | /  /" + "\033[0;35m/\\/\\\033[0;0m" + "\   \\ |        |\n"+
   " |       ||==| " + "\033[0;35m\\  /\033[0;0m" + " |==||        |\n"+
   " |        \\\\  \\_" + "\033[0;35m\\/\033[0;0m" + "_/  //         |\n"+
   " |         \\\\   ||   //          |\n"+
   " |          \\\\  ||  //           |\n"+
   " |           \\v-v-v-/            |\n"+
   " |            \\    /             |\n"+
   " |              \\/               |\n"+
   "  -------------------------------\n\n"+
   
   " Defence: +10\n"+
   " HP: +25\n"+
   " Speed: +5\n"+
   " Weight: +3 (-2 speed for every unit of weight encumbered)\n";

compshield.atkm = 0;
compshield.hpm = 25;
compshield.spdm = 5;
compshield.defm = 10;
compshield.rngm = 0;
compshield.weight = 3;
compshield.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
mushroom.name = "Mushroom";
mushroom.description = a+"Lets'a Goooo!\n\n"+
   
   "  -------------------------------\n"+
   " |                               |\n"+
   " |          __________           |\n"+
   " |       __" + "\033[41;1m/ |        \\\033[0m" + "__        |\n"+
   " |      /___" + "\033[41;1m/        /\033[0m" + "   \\       |\n"+
   " |     " + "\033[41;1m(            |\033[0m" + "     )      |\n"+
   " |     " + "\033[41;1m(___          \\\033[0m" + " __ )      |\n"+
   " |      \\__" + "\033[41;1m\\_____________/\033[0m" + "       |\n"+
   " |         |          |          |\n"+
   " |         |   |  |   |           |\n"+
   " |         |__________|           |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Speed: +10\n"+
   " Fuel Capacity: +20\n"+
   " Weight: +2 (-2 speed for every unit of weight encumbered)\n";

mushroom.atkm = 0;
mushroom.hpm = 0;
mushroom.spdm = 10;
mushroom.defm = 0;
mushroom.rngm = 0;
mushroom.weight = 2;
mushroom.fuelm = 20;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
mastersword.name = "Master Sword";
mastersword.description = a+"The Blade of Evil's Bane, and faithful sword of the Hero of Time.\n\n"+
   
   "  -------------------------------\n" +
   " |\033[0;34m             ( )               \033[0m|\n"+
   " |\033[0;34m          ___| |___            \033[0m|\n"+
   " |\033[0;34m         / __/ \\__ \\           \033[0m|\n"+
   " |\033[0;34m        // \033[0m  | || \033[0;34m \\\\          \033[0m|\n"+
   " |            |   ||             |\n"+ 
   " |            |   ||             |\n"+
   " |            |   ||             |\n"+
   " |            |   ||             |\n"+
   " |            |   ||             |\n"+
   " |             \\  /              |\n"+
   " |              \\/               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +30\n"+
   " Weapon Range: 4\n"+
   " Weight: +5 (-2 speed for every unit of weight encumbered) \n";

mastersword.atkm = 30;
mastersword.hpm = 0;
mastersword.spdm = 0;
mastersword.defm = 0;
mastersword.rngm = 4;
mastersword.weight = 5;
mastersword.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ring.name = "The One Ring";
ring.description = a+
   "The greatest of the Rings of Power and the most powerful artifact in\n"+
   "all of Middle-Earth.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |                               |\n"+
   " |\033[0;33m            .- - -.            \033[0m|\n"+
   " |\033[0;33m         .'  .- -.  '.         \033[0m|\n"+
   " |\033[0;33m       /  /         \\  \\       \033[0m|\n"+
   " |\033[0;33m      |  |           |  |      \033[0m|\n"+
   " |\033[0;33m       \\  \\          /  /      \033[0m|\n"+
   " |\033[0;33m         . '._ _ _ .' .'       \033[0m|\n"+
   " |\033[0;33m          '._ _  _ _.'         \033[0m|\n"+
   " |                               |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Speed: +40\n"+
   " Evil Curse (Weight): +7 (-2 speed for every unit of weight encumbered) \n";

ring.atkm = 0;
ring.hpm = 0;
ring.spdm = 40;
ring.defm = 0;
ring.rngm = 0;
ring.weight = 7;
ring.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
force.name = "The Force";
force.description = a+
   "The Force is what gives a Jedi his power. It's an energy field created\n"+
   "by all living things. It surrounds us and penetrates us. It binds the\n"+
   "galaxy together.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |                      \\        |\n"+
   " |                 \\     ||      |\n"+
   " |            \\     ||    ||     |\n"+
   " |   ~-~-~-~   ||     ||   ||    |\n"+
   " |   -~-~-~-    |      |    |    |\n"+
   " |   ~-~-~-~   ||     ||   ||    |\n"+
   " |            /     ||    ||     |\n"+
   " |                 /     ||      |\n"+
   " |                      /        |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +10\n"+
   " Speed: +25\n"+
   " Weapon Range: 10\n"+
   " Mental Toll (Weight) +5 (-2 speed for every unit of weight encumbered) \n";

force.atkm = 10;
force.hpm = 0;
force.spdm = 25;
force.defm = 0;
force.rngm = 10;
force.weight = 5;
force.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
mjolnir.name = "Mjolnir";
mjolnir.description = a+"The hammer of Thor, god of thunder.\n\n"+
   "  -------------------------------\n" +
   " |    ___________________        |\n"+
   " |   | |               | |       |\n"+
   " |   |*|      ___      |*|       |\n"+
   " |   |*|_____/   \\_____|*|       |\n"+
   " |   |_______     _______|       |\n"+
   " |\033[0;33m           |   |               \033[0m|\n"+
   " |\033[0;33m           |\\-/|               \033[0m|\n"+
   " |\033[0;33m           | / |               \033[0m|\n"+
   " |\033[0;33m           |/-\\|               \033[0m|\n"+
   " |\033[0;33m           |___|__             \033[0m|\n"+
   " |\033[0;33m                \\/             \033[0m|\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +45\n"+
   " Weapon Range: 8\n"+
   " Weight: +9 (-2 speed for every unit of weight encumbered) \n";

mjolnir.atkm = 45;
mjolnir.hpm = 0;
mjolnir.spdm = 0;
mjolnir.defm = 0;
mjolnir.rngm = 8;
mjolnir.weight = 9;
mjolnir.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
elderwand.name = "Elder Wand";
elderwand.description = a+
   "The most powerful wand in existence, made of elder wood and with a\n"+
   "cor of a Thestral tail hair.\n\n"+
   
   "  -------------------------------\n" +
   " |               //  ~     *     |\n"+
   " |             _//     *         |\n"+
   " |            \\ _\\    ~    ~     |\n"+
   " |           _//                 |\n"+
   " |          \\ _\\         *       |\n"+
   " |         _//                   |\n"+
   " |        \\ _\\                   |\n"+
   " |        / /                    |\n"+
   " |      _/ /                     |\n"+
   " |      \\__|                     |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +35\n"+
   " Weapon Range: 10\n"+
   " Weight: +6 (-2 speed for every unit of weight encumbered) \n";

elderwand.atkm = 35;
elderwand.hpm = 0;
elderwand.spdm = 0;
elderwand.defm = 0;
elderwand.rngm = 10;
elderwand.weight = 6;
elderwand.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
phaser.name = "Phaser";
phaser.description = a+
   "\n\n"+
   "This gun is perfect for those boldy going wherever they need to go.\n\n"+
  

   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |\033[0;36m           _\033[0m" + "_______" + "\033[0;36m____  \033[0m      |\n"+
   " |\033[0;36m          / \033[0m" + "\\_____/    \033[0;36m\\       \033[0m|\n"+
   " |\033[0;36m      ___/      ________\\      \033[0m|\n"+
   " |    <=\033[0;36m____     /               \033[0m|\n"+
   " |          |\\   \\               |\n"+
   " |            \\   \\              |\n"+
   " |             \\   \\             |\n"+
   " |              \\___\\            |\n"+
   " |                               |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " \n"+
   " Attack: +10\n"+
   " Weapon Range: 5 \n"+
   " Weight: +1  (-2 speed for every unit of weight encumbered) \n";

phaser.atkm = 10;
phaser.hpm = 0;
phaser.spdm = 0;
phaser.defm = 0;
phaser.rngm = 5;
phaser.weight = 1;
phaser.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
herb.name = "Red Herb";
herb.description = a+
   "Freshly grown in Raccoon City, it gives the user a boost in energy.\n\n"+
   
   "  -------------------------------\n" +
   " |\033[0;31m         __  |                 \033[0m|\n"+
   " |\033[0;31m        /__\\_||  _____         \033[0m|\n"+
   " |\033[0;31m             || /_____\\        \033[0m|\n"+
   " |\033[0;31m      ______  ||               \033[0m|\n"+
   " |\033[0;31m     /______\\ ||               \033[0m|\n"+
   " |\033[0;31m             ||                \033[0m|\n"+
   " |\033[0;33m          ___\033[0;31m||\033[0;33m___             \033[0m|\n"+
   " |\033[0;33m         \\--------/            \033[0m|\n"+
   " |\033[0;33m          \\      /             \033[0m|\n"+
   " |\033[0;33m           \\____/              \033[0m|\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Fuel Capacity: +20\n"+
   " Weight: +1 (-2 speed for every unit of weight encumbered) \n";

herb.atkm = 0;
herb.hpm = 0;
herb.spdm = 0;
herb.defm = 0;
herb.rngm = 0;
herb.weight = 1;
herb.fuelm = 20;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
capshield.name = "Captain's Shield";
capshield.description = a+
   "Made of vibranium, it is the shield of Captain America.\n\n"+
   
   "  -------------------------------\n" +
   " |           \033[41;31;1m       \033[0m             |\n"+
   " |        \033[41;31;1m   \033[0m       \033[41;31;1m   \033[0m          |\n"+
   " |      \033[41;31;1m  \033[0m    \033[44;37;1m     \033[0m    \033[41;31;1m  \033[0m        |\n"+
   " |     \033[41;31;1m \033[0m   \033[44;37;1m     .     \033[0m   \033[41;31;1m \033[0m       |\n"+
   " |    \033[41;31;1m \033[0m  \033[44;37;1m    __.'.__    \033[0m  \033[41;31;1m \033[0m      |\n"+
   " |    \033[41;31;1m \033[0m  \033[44;37;1m   '-.   .-'   \033[0m  \033[41;31;1m \033[0m      |\n"+
   " |    \033[41;31;1m \033[0m  \033[44;37;1m     /.'.\\     \033[0m  \033[41;31;1m \033[0m      |\n"+
   " |     \033[41;31;1m \033[0m   \033[44;37;1m   '   '   \033[0m   \033[41;31;1m \033[0m       |\n"+
   " |      \033[41;31;1m  \033[0m    \033[44;37;1m     \033[0m    \033[41;31;1m  \033[0m        |\n"+
   " |        \033[41;31;1m   \033[0m       \033[41;31;1m   \033[0m          |\n"+
   " |           \033[41;31;1m       \033[0m             |\n"+
   "  -------------------------------\n\n"+

   " Attack: +5\n"+
   " Defence: +30\n"+
   " Weapon Range: 4\n"+
   " Weight: +5 (-2 speed for every unit of weight encumbered) \n";

capshield.atkm = 5;
capshield.hpm = 0;
capshield.spdm = 0;
capshield.defm = 30;
capshield.rngm = 4;
capshield.weight = 5;
capshield.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
batarang.name = "Batarang";
batarang.description = a+
   "Weapon of choice for Gotham's Dark Knight.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |                               |\n"+
   " |    ______           ______    |\n"+
   " |     \\    \\___|-|___/     /    |\n"+
   " |      )__              __(     |\n"+
   " |         \\____    ____/        |\n"+
   " |              \\  /             |\n"+
   " |               \\/              |\n"+
   " |                               |\n"+
   " |                               |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +20\n"+
   " Weapon Range: 5\n"+
   " Weight: +3 (-2 speed for every unit of weight encumbered) \n";

batarang.atkm = 20;
batarang.hpm = 0;
batarang.spdm = 0;
batarang.defm = 0;
batarang.rngm = 5;
batarang.weight = 3;
batarang.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
rahgot.name = "Rahgot";
rahgot.description = a+
   "Mask of the dragon preist Rahgot of Skyrim.\n\n"+
   
   "  -------------------------------\n" +
   " |\033[0;32m            ___                \033[0m|\n"+
   " |\033[0;32m         _-' 0 '-_             \033[0m|\n"+
   " |\033[0;32m        /-__\\ /__-\\            \033[0m|\n"+
   " |\033[0;32m       /  _ \\ / _  \\           \033[0m|\n"+
   " |\033[0;32m       | /_\\ | /_\\ |           \033[0m|\n"+
   " |\033[0;32m       | \\_/ _ \\_/ |           \033[0m|\n"+
   " |\033[0;32m       |   _/ \\_   |           \033[0m|\n"+
   " |\033[0;32m       |  /_---_\\  |           \033[0m|\n"+
   " |\033[0;32m        \\   / \\   /            \033[0m|\n"+
   " |\033[0;32m          \\_____/              \033[0m|\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Fuel Capacity: +60\n"+
   " Weight: +5 (-2 speed for every unit of weight encumbered) \n";

rahgot.atkm = 0;
rahgot.hpm = 0;
rahgot.spdm = 0;
rahgot.defm = 0;
rahgot.rngm = 0;
rahgot.weight = 5;
rahgot.fuelm = 60;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
needler.name = "Needler";
needler.description = a+
   "Available in several models, the wimpy, dual wield, and ordenance \n"+
   "versions of this iconic weapon will leave your foes fearing the pink\n"+
   "mist.\n\n"+
   
   "  -------------------------------\n" +
   " |\033[1;35m            /     /            \033[0m|\n"+
   " |\033[1;35m           /  /  /  /          \033[0m|\n"+
   " |\033[0;35m        __\033[1;35m/\033[0;35m__\033[1;35m/\033[0;35m__\033[1;35m/\033[0;35m__\033[1;35m/\033[0;35m_          \033[0m|\n"+
   " |\033[0;35m       / ___\033[1;35m/\033[0;35m_____\033[1;35m/\033[0;35m__\\__       \033[0m|\n"+
   " |\033[0;35m      |                 |      \033[0m|\n"+
   " |\033[0;35m   __/      ____ ______/       \033[0m|\n"+
   " |\033[0;35m   __ \033[1;36m===\033[0;35m  |    |              \033[0m|\n"+
   " |\033[0;35m     \\_    |    |_____         \033[0m|\n"+
   " |\033[0;35m       \\    \\__/      \\        \033[0m|\n"+
   " |\033[0;35m        \\______________|       \033[0m|\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +20\n"+
   " Speed:  +10\n"+
   " Weapon Range: 3\n"+
   " Weight:  +3 (-2 speed for every unit of weight encumbered)\n";

needler.atkm = 20;
needler.hpm = 0;
needler.spdm = 10;
needler.defm = 0;
needler.rngm = 3;
needler.weight = 3;
needler.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
maximmato.name = "Maxim Tomato";
maximmato.description = a+
   "Glowing, red tomatoes that are found in Dream Land. They heal the user\n"+
   "substantially.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |                               |\n"+
   " |\033[1;32m              __               \033[0m|\n"+
   " |\033[1;32m          ____\033[42;32;1m||\033[0m\033[1;32m____           \033[0m|\n"+
   " |       __'\033[41;32;1m/\\/\\/\\/\\/\\\033[0m'__        |\n"+
   " |     _\033[41;30;1m'    ___  ___    '\033[0m_      |\n"+
   " |     \033[41;30;1m|    \033[0m|   \\/   |\033[41;30;1m    |\033[0m      |\n"+
   " |     \033[41;30;1m|    \033[0m|_|\\__/|_|\033[41;30;1m    |\033[0m      |\n"+
   " |      \033[41;30;1m'__            __'\033[0m       |\n"+
   " |         \033[41;30;1m'__________'\033[0m          |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Health Points: +100\n"+
   " Weight:  +5 (-2 speed for every unit of weight encumbered)\n";

maximmato.atkm = 0;
maximmato.hpm = 100;
maximmato.spdm = 0;
maximmato.defm = 0;
maximmato.rngm = 0;
maximmato.weight = 5;
maximmato.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
hpup.name = "HP Up";
hpup.description = a+
   "Available for purchase in the Celadon City Department Store, this \n"+
   "vitamin drink raises the health points and fuel of the user.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |\033[0;32m            ______             \033[0m|\n"+
   " |\033[0;32m           |      |            \033[0m|\n"+
   " |\033[0;33m          _\033[0;32m|\033[0;33m______\033[0;32m|\033[0;33m_           \033[0m|\n"+
   " |         |----------|          |\n"+
   " |         |    \033[0;36m/\\\033[0m    |          \033[0m|\n"+
   " |         |   \033[0;36m/  \\\033[0m   |          \033[0m|\n"+
   " |         |    \033[4;36m/\\\033[0m    |          \033[0m|\n"+
   " |         |----------|          |\n"+
   " |\033[0;33m         |__________|          \033[0m|\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Health Points: +50\n"+
   " Fuel Capacity: +20\n"+
   " Weight:  +4 (-2 speed for every unit of weight encumbered)\n";

hpup.atkm = 0;
hpup.hpm = 50;
hpup.spdm = 0;
hpup.defm = 0;
hpup.rngm = 0;
hpup.weight = 4;
hpup.fuelm = 20;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
goldgun.name = "Golden Gun";
goldgun.description = a+
   "Designed by Q, this gun was a deadly and stylish addition to Bond's\n"+
   "armory. Recoil makes it somewhat less accurate.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |\033[0;33m |\\___________________/|___    \033[0m|\n"+
   " |\033[0;33m | ______________         /    \033[0m|\n"+
   " |\033[0;33m |                      (__    \033[0m|\n"+
   " |\033[0;33m |_____________ ___ ____ ___\\  \033[0m|\n"+
   " |\033[0;33m               | ) |  . (      \033[0m|\n"+
   " |\033[0;33m               |___|.   |      \033[0m|\n"+
   " |\033[0;33m                   | . . \\     \033[0m|\n"+
   " |\033[0;33m                   | .  .|     \033[0m|\n"+
   " |\033[0;33m                   |_____|     \033[0m|\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +55\n"+
   " Weapon Range: 7\n"+
   " Weight: +10 (-2 speed for every unit of weight encumbered)\n";

goldgun.atkm = 55;
goldgun.hpm = 0;
goldgun.spdm = 0;
goldgun.defm = 0;
goldgun.rngm = 7;
goldgun.weight = 10;
goldgun.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
chain.name = "Kunai With Chain";
chain.description = a+
   "Modeled after the popular Duel Monsters card, this weapon is deadly and\n"+
   "surprisingly light.\n\n"+
   
   "  -------------------------------\n" +
   " |        /\\         ____        |\n"+
   " |       /  \\       |  _/        |\n"+
   " |      /_   \\     /  /          |\n"+
   " |        )  /    /  /           |\n"+
   " |         \ \\   /  /            |\n"+
   " |          \ \\_/  /             |\n"+
   " |      /(__) ____/              |\n"+
   " |      |    (_  ()              |\n"+
   " |       '____/  ()              |\n"+
   " |                <><><>         |\n"+
   " |                    ()         |\n"+
   "  -------------------------------\n\n"+
   
   " Attack: +25\n"+
   " Weapon Range: 6\n"+
   " Weight: +4 (-2 speed for every unit of weight encumbered)\n";

chain.atkm = 25;
chain.hpm = 0;
chain.spdm = 0;
chain.defm = 0;
chain.rngm = 6;
chain.weight = 4;
chain.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cherry.name = "Cherry";
cherry.description = a+
   "WAKA WAKA WAKA WAKA!\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |\033[0;32m               _               \033[0m|\n"+
   " |\033[0;32m              / |              \033[0m|\n"+
   " |\033[0;32m             /  |              \033[0m|\n"+
   " |\033[0;32m            /   |              \033[0m|\n"+
   " |\033[0;31m        __ \033[0;32m/\033[0;31m  __\033[0;32m|              \033[0m|\n"+
   " |\033[0;31m       /  \033[0;32m/\033[0;31m\\ /  \033[0;32m|\033[0;31m\\             \033[0m|\n"+
   " |\033[0;31m      |\033[0;37m(\033[0;31m    |\033[0;37m(\033[0;31m    |            \033[0m|\n"+
   " |\033[0;31m       \\___/ \\___/             \033[0m|\n"+  
   " |                               |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Speed: +15\n"+
   " Health Points: +50\n"+
   " Weight: +4 (-2 speed for every unit of weight encumbered)\n";

cherry.atkm = 0;
cherry.hpm = 50;
cherry.spdm = 15;
cherry.defm = 0;
cherry.rngm = 0;
cherry.weight = 4;
cherry.fuelm = 0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
chaos.name = "Chaos Emerald";
chaos.description = a+
   "One of the seven powerful relics used by Sonic the Hedgehog.\n\n"+
   
   "  -------------------------------\n" +
   " |                               |\n"+
   " |\033[0;36m                   _______     \033[0m|\n"+
   " |\033[0;36m                 .'_/_|_\\_'.   \033[0m|\n"+
   " |\033[0;36m                 \\`\\  |  /`/   \033[0m|\n"+
   " |\033[0;32m     _______     \033[0;36m `\\\\ | //'    \033[0m|\n"+          
   " |\033[0;32m   .'_/_|_\\_'.   \033[0;36m   `\\|/`      \033[0m|\n"+
   " |\033[0;32m   \\`\\  |  /`/                 \033[0m|\n"+
   " |\033[0;32m    `\\\\ | //'                  \033[0m|\n"+
   " |\033[0;32m      `\\|/`                    \033[0m|\n"+  
   " |                               |\n"+
   " |                               |\n"+
   "  -------------------------------\n\n"+
   
   " Speed: +10\n"+
   " Health Points: +20\n"+
   " Attack: +10\n"+
   " Defence: +10\n"+
   " Fuel Capacity: +20\n"+
   " Weight: +5 (-2 speed for every unit of weight encumbered)\n";

chaos.atkm = 10;
chaos.hpm = 20;
chaos.spdm = 10;
chaos.defm = 10;
chaos.rngm = 0;
chaos.weight = 5;
chaos.fuelm = 20;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// puts attachments into the array
attachments.push_back(nunchucks);
attachments.push_back(compshield);
attachments.push_back(mushroom);
attachments.push_back(mastersword);
attachments.push_back(ring);
attachments.push_back(force);
attachments.push_back(mjolnir);
attachments.push_back(elderwand);
attachments.push_back(phaser);
attachments.push_back(herb);
attachments.push_back(capshield);
attachments.push_back(batarang);
attachments.push_back(rahgot);
attachments.push_back(needler);
attachments.push_back(maximmato);
attachments.push_back(hpup);
attachments.push_back(goldgun);
attachments.push_back(chain);
attachments.push_back(cherry);
attachments.push_back(chaos);
return attachments;
}
