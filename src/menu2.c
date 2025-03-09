#include "global.h"
#include "gflib.h"
#include "task.h"
#include "wild_encounter.h"

// Not actually "old" given these were introduced in Gen 3,
// but they're used as equivalents here alongside the other OLD_WEAVILE
#define SPECIES_OLD_UNOWN_EMARK (NUM_SPECIES + 0)
#define SPECIES_OLD_UNOWN_QMARK (NUM_SPECIES + 1)

static void Task_SmoothBlendLayers(u8 taskId);

static const u8 sMonSpriteAnchorCoords[][5] = {
    [SPECIES_BULBASAUR       - 1] = {0x16, 0x1b, 0x30, 0x16, 0x29},
    [SPECIES_IVYSAUR         - 1] = {0x14, 0x1b, 0x30, 0x15, 0x2a},
    [SPECIES_VENUSAUR        - 1] = {0x1b, 0x20, 0x20, 0x1b, 0x33},
    [SPECIES_CHARMANDER      - 1] = {0x14, 0x0f, 0x38, 0x13, 0x1e},
    [SPECIES_CHARMELEON      - 1] = {0x0d, 0x11, 0x30, 0x0f, 0x22},
    [SPECIES_CHARIZARD       - 1] = {0x1b, 0x07, 0x28, 0x1a, 0x19},
    [SPECIES_SQUIRTLE        - 1] = {0x19, 0x13, 0x30, 0x1a, 0x22},
    [SPECIES_WARTORTLE       - 1] = {0x16, 0x13, 0x30, 0x17, 0x21},
    [SPECIES_BLASTOISE       - 1] = {0x12, 0x08, 0x28, 0x15, 0x19},
    [SPECIES_CATERPIE        - 1] = {0x15, 0x14, 0x30, 0x13, 0x24},
    [SPECIES_METAPOD         - 1] = {0x13, 0x1d, 0x30, 0x18, 0x2a},
    [SPECIES_BUTTERFREE      - 1] = {0x12, 0x1b, 0x08, 0x12, 0x2a},
    [SPECIES_WEEDLE          - 1] = {0x16, 0x1c, 0x30, 0x15, 0x2b},
    [SPECIES_KAKUNA          - 1] = {0x19, 0x13, 0x30, 0x1a, 0x24},
    [SPECIES_BEEDRILL        - 1] = {0x19, 0x16, 0x08, 0x19, 0x25},
    [SPECIES_PIDGEY          - 1] = {0x15, 0x12, 0x30, 0x12, 0x1e},
    [SPECIES_PIDGEOTTO       - 1] = {0x24, 0x0e, 0x30, 0x1f, 0x1e},
    [SPECIES_PIDGEOT         - 1] = {0x0c, 0x13, 0x08, 0x0a, 0x23},
    [SPECIES_RATTATA         - 1] = {0x17, 0x1e, 0x30, 0x18, 0x2d},
    [SPECIES_RATICATE        - 1] = {0x12, 0x14, 0x30, 0x10, 0x26},
    [SPECIES_SPEAROW         - 1] = {0x15, 0x14, 0x30, 0x15, 0x1f},
    [SPECIES_FEAROW          - 1] = {0x0c, 0x27, 0x00, 0x0b, 0x3f},
    [SPECIES_EKANS           - 1] = {0x11, 0x0f, 0x30, 0x14, 0x1d},
    [SPECIES_ARBOK           - 1] = {0x1b, 0x01, 0x28, 0x1d, 0x10},
    [SPECIES_PIKACHU         - 1] = {0x19, 0x13, 0x30, 0x1a, 0x1f},
    [SPECIES_RAICHU          - 1] = {0x19, 0x14, 0x28, 0x1c, 0x22},
    [SPECIES_SANDSHREW       - 1] = {0x17, 0x16, 0x30, 0x18, 0x25},
    [SPECIES_SANDSLASH       - 1] = {0x11, 0x13, 0x28, 0x13, 0x22},
    [SPECIES_NIDORAN_F       - 1] = {0x16, 0x15, 0x30, 0x18, 0x21},
    [SPECIES_NIDORINA        - 1] = {0x1f, 0x17, 0x30, 0x1e, 0x28},
    [SPECIES_NIDOQUEEN       - 1] = {0x10, 0x0b, 0x28, 0x13, 0x1c},
    [SPECIES_NIDORAN_M       - 1] = {0x15, 0x22, 0x28, 0x15, 0x31},
    [SPECIES_NIDORINO        - 1] = {0x13, 0x1e, 0x28, 0x1b, 0x2d},
    [SPECIES_NIDOKING        - 1] = {0x12, 0x15, 0x28, 0x13, 0x27},
    [SPECIES_CLEFAIRY        - 1] = {0x19, 0x14, 0x30, 0x1b, 0x24},
    [SPECIES_CLEFABLE        - 1] = {0x1c, 0x12, 0x30, 0x1d, 0x21},
    [SPECIES_VULPIX          - 1] = {0x10, 0x16, 0x30, 0x0e, 0x25},
    [SPECIES_NINETALES       - 1] = {0x28, 0x10, 0x28, 0x27, 0x1e},
    [SPECIES_JIGGLYPUFF      - 1] = {0x1d, 0x15, 0x30, 0x1e, 0x25},
    [SPECIES_WIGGLYTUFF      - 1] = {0x1a, 0x12, 0x30, 0x1c, 0x22},
    [SPECIES_ZUBAT           - 1] = {0x14, 0x1d, 0x08, 0x14, 0x29},
    [SPECIES_GOLBAT          - 1] = {0x23, 0x1a, 0x00, 0x21, 0x2e},
    [SPECIES_ODDISH          - 1] = {0x1d, 0x20, 0x28, 0x1d, 0x2b},
    [SPECIES_GLOOM           - 1] = {0x1c, 0x18, 0x28, 0x1c, 0x27},
    [SPECIES_VILEPLUME       - 1] = {0x1c, 0x1e, 0x28, 0x1d, 0x2a},
    [SPECIES_PARAS           - 1] = {0x1d, 0x1a, 0x30, 0x1c, 0x27},
    [SPECIES_PARASECT        - 1] = {0x1e, 0x1c, 0x28, 0x20, 0x2e},
    [SPECIES_VENONAT         - 1] = {0x1b, 0x16, 0x10, 0x1a, 0x29},
    [SPECIES_VENOMOTH        - 1] = {0x12, 0x19, 0x08, 0x16, 0x27},
    [SPECIES_DIGLETT         - 1] = {0x1e, 0x16, 0x30, 0x1c, 0x23},
    [SPECIES_DUGTRIO         - 1] = {0x1a, 0x11, 0x30, 0x1a, 0x1f},
    [SPECIES_MEOWTH          - 1] = {0x1c, 0x16, 0x30, 0x1c, 0x23},
    [SPECIES_PERSIAN         - 1] = {0x13, 0x13, 0x30, 0x13, 0x21},
    [SPECIES_PSYDUCK         - 1] = {0x1c, 0x13, 0x30, 0x17, 0x29},
    [SPECIES_GOLDUCK         - 1] = {0x17, 0x12, 0x28, 0x17, 0x22},
    [SPECIES_MANKEY          - 1] = {0x1c, 0x15, 0x30, 0x1b, 0x23},
    [SPECIES_PRIMEAPE        - 1] = {0x1e, 0x16, 0x30, 0x1a, 0x27},
    [SPECIES_GROWLITHE       - 1] = {0x14, 0x17, 0x30, 0x14, 0x24},
    [SPECIES_ARCANINE        - 1] = {0x0f, 0x09, 0x28, 0x0c, 0x19},
    [SPECIES_POLIWAG         - 1] = {0x15, 0x14, 0x30, 0x13, 0x1f},
    [SPECIES_POLIWHIRL       - 1] = {0x1f, 0x10, 0x30, 0x1e, 0x17},
    [SPECIES_POLIWRATH       - 1] = {0x22, 0x0c, 0x30, 0x21, 0x18},
    [SPECIES_ABRA            - 1] = {0x1f, 0x13, 0x30, 0x1f, 0x21},
    [SPECIES_KADABRA         - 1] = {0x1b, 0x12, 0x30, 0x1c, 0x25},
    [SPECIES_ALAKAZAM        - 1] = {0x1c, 0x11, 0x28, 0x1d, 0x26},
    [SPECIES_MACHOP          - 1] = {0x1b, 0x11, 0x30, 0x1b, 0x1e},
    [SPECIES_MACHOKE         - 1] = {0x1d, 0x11, 0x30, 0x1d, 0x1f},
    [SPECIES_MACHAMP         - 1] = {0x1a, 0x0d, 0x28, 0x1c, 0x1b},
    [SPECIES_BELLSPROUT      - 1] = {0x15, 0x0e, 0x30, 0x0e, 0x1c},
    [SPECIES_WEEPINBELL      - 1] = {0x1a, 0x1c, 0x10, 0x15, 0x32},
    [SPECIES_VICTREEBEL      - 1] = {0x1e, 0x0f, 0x30, 0x1c, 0x1b},
    [SPECIES_TENTACOOL       - 1] = {0x1a, 0x15, 0x30, 0x1e, 0x26},
    [SPECIES_TENTACRUEL      - 1] = {0x1b, 0x10, 0x28, 0x1c, 0x26},
    [SPECIES_GEODUDE         - 1] = {0x1c, 0x20, 0x28, 0x1d, 0x2d},
    [SPECIES_GRAVELER        - 1] = {0x1d, 0x19, 0x28, 0x1e, 0x26},
    [SPECIES_GOLEM           - 1] = {0x19, 0x1b, 0x28, 0x1c, 0x27},
    [SPECIES_PONYTA          - 1] = {0x0f, 0x11, 0x30, 0x0e, 0x23},
    [SPECIES_RAPIDASH        - 1] = {0x2f, 0x0f, 0x28, 0x2b, 0x1e},
    [SPECIES_SLOWPOKE        - 1] = {0x14, 0x1f, 0x28, 0x15, 0x2f},
    [SPECIES_SLOWBRO         - 1] = {0x0e, 0x0d, 0x28, 0x0c, 0x1f},
    [SPECIES_MAGNEMITE       - 1] = {0x20, 0x1b, 0x10, 0x1f, 0x29},
    [SPECIES_MAGNETON        - 1] = {0x1f, 0x14, 0x08, 0x1f, 0x22},
    [SPECIES_FARFETCHD       - 1] = {0x16, 0x14, 0x30, 0x16, 0x29},
    [SPECIES_DODUO           - 1] = {0x11, 0x16, 0x30, 0x0d, 0x2c},
    [SPECIES_DODRIO          - 1] = {0x1d, 0x04, 0x28, 0x0e, 0x07},
    [SPECIES_SEEL            - 1] = {0x1b, 0x24, 0x20, 0x17, 0x35},
    [SPECIES_DEWGONG         - 1] = {0x12, 0x0a, 0x30, 0x0e, 0x1a},
    [SPECIES_GRIMER          - 1] = {0x1f, 0x10, 0x30, 0x1d, 0x25},
    [SPECIES_MUK             - 1] = {0x17, 0x0f, 0x30, 0x19, 0x22},
    [SPECIES_SHELLDER        - 1] = {0x1a, 0x18, 0x30, 0x17, 0x29},
    [SPECIES_CLOYSTER        - 1] = {0x19, 0x1e, 0x28, 0x1d, 0x2c},
    [SPECIES_GASTLY          - 1] = {0x1a, 0x1f, 0x08, 0x19, 0x30},
    [SPECIES_HAUNTER         - 1] = {0x20, 0x14, 0x08, 0x1d, 0x26},
    [SPECIES_GENGAR          - 1] = {0x1a, 0x16, 0x30, 0x19, 0x28},
    [SPECIES_ONIX            - 1] = {0x1f, 0x24, 0x20, 0x28, 0x36},
    [SPECIES_DROWZEE         - 1] = {0x1a, 0x0e, 0x30, 0x1a, 0x1e},
    [SPECIES_HYPNO           - 1] = {0x1c, 0x12, 0x30, 0x19, 0x24},
    [SPECIES_KRABBY          - 1] = {0x1d, 0x1d, 0x30, 0x1a, 0x2b},
    [SPECIES_KINGLER         - 1] = {0x1e, 0x1f, 0x28, 0x1c, 0x30},
    [SPECIES_VOLTORB         - 1] = {0x1c, 0x1b, 0x30, 0x1b, 0x2b},
    [SPECIES_ELECTRODE       - 1] = {0x1c, 0x18, 0x30, 0x1d, 0x2e},
    [SPECIES_EXEGGCUTE       - 1] = {0x21, 0x17, 0x30, 0x20, 0x24},
    [SPECIES_EXEGGUTOR       - 1] = {0x1c, 0x17, 0x28, 0x1b, 0x25},
    [SPECIES_CUBONE          - 1] = {0x1b, 0x12, 0x30, 0x1b, 0x22},
    [SPECIES_MAROWAK         - 1] = {0x14, 0x0f, 0x30, 0x11, 0x23},
    [SPECIES_HITMONLEE       - 1] = {0x2e, 0x11, 0x30, 0x28, 0x22},
    [SPECIES_HITMONCHAN      - 1] = {0x22, 0x0e, 0x30, 0x1e, 0x1d},
    [SPECIES_LICKITUNG       - 1] = {0x14, 0x11, 0x30, 0x14, 0x24},
    [SPECIES_KOFFING         - 1] = {0x1e, 0x14, 0x10, 0x1d, 0x20},
    [SPECIES_WEEZING         - 1] = {0x11, 0x0d, 0x10, 0x0f, 0x1c},
    [SPECIES_RHYHORN         - 1] = {0x0e, 0x23, 0x20, 0x14, 0x33},
    [SPECIES_RHYDON          - 1] = {0x0d, 0x12, 0x28, 0x17, 0x22},
    [SPECIES_CHANSEY         - 1] = {0x1a, 0x0d, 0x30, 0x1a, 0x1a},
    [SPECIES_TANGELA         - 1] = {0x1c, 0x18, 0x30, 0x1d, 0x29},
    [SPECIES_KANGASKHAN      - 1] = {0x1b, 0x06, 0x28, 0x1c, 0x14},
    [SPECIES_HORSEA          - 1] = {0x1c, 0x14, 0x30, 0x16, 0x23},
    [SPECIES_SEADRA          - 1] = {0x10, 0x17, 0x30, 0x09, 0x2a},
    [SPECIES_GOLDEEN         - 1] = {0x16, 0x23, 0x20, 0x15, 0x34},
    [SPECIES_SEAKING         - 1] = {0x16, 0x0f, 0x30, 0x10, 0x18},
    [SPECIES_STARYU          - 1] = {0x1c, 0x18, 0x30, 0x1a, 0x26},
    [SPECIES_STARMIE         - 1] = {0x1d, 0x13, 0x30, 0x1b, 0x20},
    [SPECIES_MR_MIME         - 1] = {0x24, 0x11, 0x30, 0x25, 0x1e},
    [SPECIES_SCYTHER         - 1] = {0x10, 0x19, 0x28, 0x12, 0x27},
    [SPECIES_JYNX            - 1] = {0x1b, 0x0f, 0x30, 0x19, 0x1c},
    [SPECIES_ELECTABUZZ      - 1] = {0x14, 0x11, 0x30, 0x17, 0x20},
    [SPECIES_MAGMAR          - 1] = {0x10, 0x0e, 0x30, 0x0b, 0x19},
    [SPECIES_PINSIR          - 1] = {0x1d, 0x1c, 0x28, 0x20, 0x2b},
    [SPECIES_TAUROS          - 1] = {0x11, 0x1d, 0x28, 0x13, 0x2e},
    [SPECIES_MAGIKARP        - 1] = {0x16, 0x15, 0x30, 0x13, 0x23},
    [SPECIES_GYARADOS        - 1] = {0x0b, 0x18, 0x28, 0x16, 0x29},
    [SPECIES_LAPRAS          - 1] = {0x16, 0x08, 0x28, 0x15, 0x16},
    [SPECIES_DITTO           - 1] = {0x24, 0x12, 0x30, 0x1f, 0x20},
    [SPECIES_EEVEE           - 1] = {0x16, 0x16, 0x30, 0x16, 0x23},
    [SPECIES_VAPOREON        - 1] = {0x18, 0x23, 0x28, 0x18, 0x30},
    [SPECIES_JOLTEON         - 1] = {0x14, 0x1b, 0x30, 0x16, 0x28},
    [SPECIES_FLAREON         - 1] = {0x16, 0x17, 0x30, 0x14, 0x25},
    [SPECIES_PORYGON         - 1] = {0x18, 0x12, 0x30, 0x10, 0x23},
    [SPECIES_OMANYTE         - 1] = {0x1d, 0x1d, 0x30, 0x1c, 0x2b},
    [SPECIES_OMASTAR         - 1] = {0x16, 0x1a, 0x30, 0x19, 0x2d},
    [SPECIES_KABUTO          - 1] = {0x1b, 0x16, 0x30, 0x1a, 0x27},
    [SPECIES_KABUTOPS        - 1] = {0x15, 0x11, 0x30, 0x15, 0x1f},
    [SPECIES_AERODACTYL      - 1] = {0x13, 0x1d, 0x00, 0x14, 0x30},
    [SPECIES_SNORLAX         - 1] = {0x35, 0x09, 0x30, 0x2e, 0x14},
    [SPECIES_ARTICUNO        - 1] = {0x18, 0x0b, 0x18, 0x17, 0x17},
    [SPECIES_ZAPDOS          - 1] = {0x0e, 0x0e, 0x10, 0x04, 0x28},
    [SPECIES_MOLTRES         - 1] = {0x0b, 0x2a, 0x08, 0x0b, 0x38},
    [SPECIES_DRATINI         - 1] = {0x0d, 0x12, 0x30, 0x0b, 0x21},
    [SPECIES_DRAGONAIR       - 1] = {0x18, 0x0e, 0x30, 0x13, 0x1c},
    [SPECIES_DRAGONITE       - 1] = {0x1b, 0x07, 0x18, 0x19, 0x17},
    [SPECIES_MEWTWO          - 1] = {0x2b, 0x09, 0x28, 0x2c, 0x18},
    [SPECIES_BUDEW             - 1] = {0x19, 0x14, 0x10, 0x1f, 0x21},
    [SPECIES_CHIKORITA       - 1] = {0x1b, 0x17, 0x30, 0x1b, 0x24},
    [SPECIES_BAYLEEF         - 1] = {0x1d, 0x10, 0x30, 0x20, 0x1d},
    [SPECIES_MEGANIUM        - 1] = {0x05, 0x0d, 0x28, 0x0d, 0x1b},
    [SPECIES_CYNDAQUIL       - 1] = {0x11, 0x1b, 0x30, 0x14, 0x27},
    [SPECIES_QUILAVA         - 1] = {0x25, 0x18, 0x30, 0x27, 0x26},
    [SPECIES_TYPHLOSION      - 1] = {0x09, 0x10, 0x28, 0x10, 0x1c},
    [SPECIES_TOTODILE        - 1] = {0x16, 0x10, 0x30, 0x19, 0x20},
    [SPECIES_CROCONAW        - 1] = {0x16, 0x10, 0x30, 0x18, 0x21},
    [SPECIES_FERALIGATR      - 1] = {0x0e, 0x0a, 0x28, 0x08, 0x1a},
    [SPECIES_SENTRET         - 1] = {0x1e, 0x0a, 0x30, 0x1d, 0x15},
    [SPECIES_FURRET          - 1] = {0x21, 0x0e, 0x30, 0x21, 0x19},
    [SPECIES_HOOTHOOT        - 1] = {0x1d, 0x15, 0x30, 0x1c, 0x24},
    [SPECIES_NOCTOWL         - 1] = {0x19, 0x0e, 0x30, 0x18, 0x1c},
    [SPECIES_LEDYBA          - 1] = {0x1b, 0x15, 0x30, 0x1c, 0x24},
    [SPECIES_LEDIAN          - 1] = {0x18, 0x12, 0x10, 0x1c, 0x21},
    [SPECIES_SPINARAK        - 1] = {0x20, 0x20, 0x28, 0x20, 0x2d},
    [SPECIES_ARIADOS         - 1] = {0x17, 0x23, 0x28, 0x15, 0x30},
    [SPECIES_CROBAT          - 1] = {0x22, 0x1e, 0x08, 0x23, 0x2b},
    [SPECIES_CHINCHOU        - 1] = {0x1f, 0x1d, 0x30, 0x1f, 0x29},
    [SPECIES_LANTURN         - 1] = {0x10, 0x23, 0x28, 0x19, 0x33},
    [SPECIES_PICHU           - 1] = {0x1e, 0x17, 0x30, 0x1e, 0x24},
    [SPECIES_MIME_JR          - 1] = {0x1c, 0x18, 0x30, 0x1e, 0x26},
    [SPECIES_AMBIPOM       - 1] = {0x1f, 0x19, 0x30, 0x1f, 0x24},
    [SPECIES_TOGEPI          - 1] = {0x21, 0x15, 0x30, 0x1f, 0x20},
    [SPECIES_TOGETIC         - 1] = {0x1b, 0x10, 0x30, 0x1c, 0x1c},
    [SPECIES_NATU            - 1] = {0x1c, 0x17, 0x30, 0x15, 0x21},
    [SPECIES_XATU            - 1] = {0x1b, 0x08, 0x30, 0x19, 0x14},
    [SPECIES_MAREEP          - 1] = {0x16, 0x15, 0x30, 0x15, 0x24},
    [SPECIES_FLAAFFY         - 1] = {0x19, 0x12, 0x30, 0x18, 0x21},
    [SPECIES_AMPHAROS        - 1] = {0x0f, 0x0a, 0x30, 0x10, 0x1b},
    [SPECIES_BELLOSSOM       - 1] = {0x1f, 0x13, 0x30, 0x1f, 0x20},
    [SPECIES_MARILL          - 1] = {0x1d, 0x15, 0x30, 0x1d, 0x22},
    [SPECIES_AZUMARILL       - 1] = {0x1a, 0x12, 0x30, 0x17, 0x1f},
    [SPECIES_SUDOWOODO       - 1] = {0x20, 0x10, 0x30, 0x20, 0x1f},
    [SPECIES_POLITOED        - 1] = {0x1d, 0x0f, 0x30, 0x1e, 0x20},
    [SPECIES_HOPPIP          - 1] = {0x23, 0x25, 0x08, 0x25, 0x33},
    [SPECIES_SKIPLOOM        - 1] = {0x1e, 0x18, 0x08, 0x1c, 0x27},
    [SPECIES_JUMPLUFF        - 1] = {0x1d, 0x21, 0x08, 0x20, 0x2f},
    [SPECIES_AIPOM           - 1] = {0x1e, 0x29, 0x18, 0x1e, 0x35},
    [SPECIES_SUNKERN         - 1] = {0x1f, 0x20, 0x08, 0x24, 0x2e},
    [SPECIES_SUNFLORA        - 1] = {0x1c, 0x0c, 0x30, 0x1b, 0x19},
    [SPECIES_YANMA           - 1] = {0x1b, 0x28, 0x08, 0x16, 0x35},
    [SPECIES_WOOPER          - 1] = {0x1d, 0x13, 0x30, 0x1f, 0x21},
    [SPECIES_QUAGSIRE        - 1] = {0x15, 0x09, 0x30, 0x12, 0x18},
    [SPECIES_ESPEON          - 1] = {0x11, 0x1b, 0x30, 0x11, 0x29},
    [SPECIES_UMBREON         - 1] = {0x23, 0x15, 0x30, 0x23, 0x22},
    [SPECIES_MURKROW         - 1] = {0x24, 0x13, 0x30, 0x20, 0x22},
    [SPECIES_SLOWKING        - 1] = {0x1e, 0x13, 0x28, 0x1d, 0x25},
    [SPECIES_MISDREAVUS      - 1] = {0x28, 0x21, 0x08, 0x26, 0x2e},
    [SPECIES_WEAVILE           - 1] = {0x20, 0x17, 0x08, 0x1f, 0x21},
    [SPECIES_GLISCOR       - 1] = {0x1d, 0x09, 0x30, 0x1d, 0x1a},
    [SPECIES_GIRAFARIG       - 1] = {0x0b, 0x0d, 0x28, 0x11, 0x1d},
    [SPECIES_PINECO          - 1] = {0x1d, 0x12, 0x10, 0x19, 0x25},
    [SPECIES_FORRETRESS      - 1] = {0x19, 0x17, 0x08, 0x1e, 0x26},
    [SPECIES_DUNSPARCE       - 1] = {0x10, 0x1b, 0x30, 0x0c, 0x2d},
    [SPECIES_GLIGAR          - 1] = {0x1e, 0x13, 0x08, 0x1d, 0x23},
    [SPECIES_STEELIX         - 1] = {0x0c, 0x0d, 0x28, 0x0d, 0x1c},
    [SPECIES_SNUBBULL        - 1] = {0x1b, 0x15, 0x30, 0x1a, 0x23},
    [SPECIES_GRANBULL        - 1] = {0x1c, 0x09, 0x30, 0x19, 0x18},
    [SPECIES_QWILFISH        - 1] = {0x1f, 0x26, 0x20, 0x1d, 0x33},
    [SPECIES_SCIZOR          - 1] = {0x15, 0x0f, 0x10, 0x1a, 0x1a},
    [SPECIES_SHUCKLE         - 1] = {0x25, 0x0a, 0x30, 0x24, 0x18},
    [SPECIES_HERACROSS       - 1] = {0x18, 0x19, 0x28, 0x1a, 0x26},
    [SPECIES_SNEASEL         - 1] = {0x1c, 0x13, 0x30, 0x1d, 0x24},
    [SPECIES_TEDDIURSA       - 1] = {0x1e, 0x12, 0x30, 0x1b, 0x23},
    [SPECIES_URSARING        - 1] = {0x1e, 0x04, 0x28, 0x1d, 0x14},
    [SPECIES_SLUGMA          - 1] = {0x20, 0x18, 0x30, 0x20, 0x28},
    [SPECIES_MAGCARGO        - 1] = {0x16, 0x11, 0x30, 0x17, 0x23},
    [SPECIES_SWINUB          - 1] = {0x1c, 0x18, 0x30, 0x1b, 0x25},
    [SPECIES_PILOSWINE       - 1] = {0x18, 0x23, 0x20, 0x18, 0x36},
    [SPECIES_CORSOLA         - 1] = {0x19, 0x1d, 0x28, 0x19, 0x2b},
    [SPECIES_REMORAID        - 1] = {0x15, 0x1f, 0x28, 0x13, 0x2b},
    [SPECIES_OCTILLERY       - 1] = {0x1c, 0x11, 0x30, 0x1a, 0x20},
    [SPECIES_DELIBIRD        - 1] = {0x1d, 0x11, 0x30, 0x1b, 0x1f},
    [SPECIES_MANTINE         - 1] = {0x16, 0x1e, 0x28, 0x1f, 0x27},
    [SPECIES_SKARMORY        - 1] = {0x1e, 0x00, 0x28, 0x13, 0x07},
    [SPECIES_HOUNDOUR        - 1] = {0x25, 0x11, 0x30, 0x25, 0x1f},
    [SPECIES_HOUNDOOM        - 1] = {0x0d, 0x13, 0x30, 0x0d, 0x24},
    [SPECIES_KINGDRA         - 1] = {0x0e, 0x13, 0x28, 0x0a, 0x2c},
    [SPECIES_PHANPY          - 1] = {0x1b, 0x11, 0x30, 0x19, 0x24},
    [SPECIES_DONPHAN         - 1] = {0x11, 0x15, 0x30, 0x19, 0x2c},
    [SPECIES_PORYGON2        - 1] = {0x18, 0x11, 0x30, 0x11, 0x20},
    [SPECIES_STANTLER        - 1] = {0x15, 0x15, 0x28, 0x17, 0x28},
    [SPECIES_PROBOPASS        - 1] = {0x18, 0x10, 0x30, 0x1b, 0x25},
    [SPECIES_TYROGUE         - 1] = {0x1e, 0x12, 0x30, 0x1f, 0x1f},
    [SPECIES_HITMONTOP       - 1] = {0x1a, 0x39, 0x10, 0x1a, 0x2b},
    [SPECIES_SMOOCHUM        - 1] = {0x20, 0x18, 0x30, 0x21, 0x26},
    [SPECIES_ELEKID          - 1] = {0x1d, 0x14, 0x30, 0x1d, 0x23},
    [SPECIES_MAGBY           - 1] = {0x1c, 0x15, 0x30, 0x1a, 0x24},
    [SPECIES_MILTANK         - 1] = {0x18, 0x0e, 0x30, 0x18, 0x1e},
    [SPECIES_BLISSEY         - 1] = {0x1d, 0x09, 0x30, 0x1d, 0x19},
    [SPECIES_ROSERADE          - 1] = {0x29, 0x0c, 0x28, 0x27, 0x1e},
    [SPECIES_TANGROWTH           - 1] = {0x08, 0x09, 0x28, 0x0b, 0x18},
    [SPECIES_YANMEGA         - 1] = {0x23, 0x1d, 0x28, 0x26, 0x2c},
    [SPECIES_LARVITAR        - 1] = {0x1c, 0x18, 0x30, 0x1a, 0x24},
    [SPECIES_PUPITAR         - 1] = {0x1b, 0x19, 0x30, 0x1b, 0x28},
    [SPECIES_TYRANITAR       - 1] = {0x06, 0x0b, 0x28, 0x0d, 0x19},
    [SPECIES_MISMAGIUS           - 1] = {0x08, 0x2a, 0x08, 0x14, 0x34},
    [SPECIES_HONCHKROW           - 1] = {0x0d, 0x25, 0x08, 0x0e, 0x34},
    [SPECIES_FROSLASS          - 1] = {0x15, 0x21, 0x08, 0x1a, 0x2b},
    [SPECIES_OLD_UNOWN_B     - 1] = {0x1f, 0x12, 0x08, 0x1e, 0x1c},
    [SPECIES_OLD_UNOWN_C     - 1] = {0x20, 0x17, 0x08, 0x1f, 0x21},
    [SPECIES_OLD_UNOWN_D     - 1] = {0x1c, 0x19, 0x08, 0x1b, 0x23},
    [SPECIES_OLD_UNOWN_E     - 1] = {0x21, 0x19, 0x08, 0x20, 0x23},
    [SPECIES_OLD_UNOWN_F     - 1] = {0x1b, 0x13, 0x08, 0x1a, 0x1d},
    [SPECIES_OLD_UNOWN_G     - 1] = {0x20, 0x16, 0x08, 0x1f, 0x21},
    [SPECIES_OLD_UNOWN_H     - 1] = {0x20, 0x19, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_I     - 1] = {0x20, 0x19, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_J     - 1] = {0x20, 0x16, 0x08, 0x1f, 0x20},
    [SPECIES_OLD_UNOWN_K     - 1] = {0x1d, 0x1a, 0x08, 0x1c, 0x24},
    [SPECIES_OLD_UNOWN_L     - 1] = {0x20, 0x16, 0x08, 0x1f, 0x1f},
    [SPECIES_OLD_UNOWN_M     - 1] = {0x20, 0x1c, 0x08, 0x1f, 0x26},
    [SPECIES_OLD_UNOWN_N     - 1] = {0x20, 0x1a, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_O     - 1] = {0x20, 0x1a, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_P     - 1] = {0x20, 0x16, 0x08, 0x1f, 0x20},
    [SPECIES_OLD_UNOWN_Q     - 1] = {0x1d, 0x16, 0x08, 0x1c, 0x20},
    [SPECIES_OLD_UNOWN_R     - 1] = {0x20, 0x15, 0x08, 0x1f, 0x1f},
    [SPECIES_OLD_UNOWN_S     - 1] = {0x20, 0x19, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_T     - 1] = {0x20, 0x1e, 0x08, 0x1f, 0x28},
    [SPECIES_OLD_UNOWN_U     - 1] = {0x20, 0x17, 0x08, 0x1f, 0x21},
    [SPECIES_OLD_UNOWN_V     - 1] = {0x1e, 0x1e, 0x08, 0x1d, 0x28},
    [SPECIES_OLD_UNOWN_W     - 1] = {0x20, 0x1d, 0x08, 0x1f, 0x27},
    [SPECIES_OLD_UNOWN_X     - 1] = {0x20, 0x19, 0x08, 0x1f, 0x23},
    [SPECIES_OLD_UNOWN_Y     - 1] = {0x20, 0x15, 0x08, 0x1f, 0x1f},
    [SPECIES_OLD_UNOWN_Z     - 1] = {0x20, 0x19, 0x08, 0x1f, 0x23},
    [SPECIES_TREECKO         - 1] = {0x1a, 0x0f, 0x30, 0x19, 0x20},
    [SPECIES_GROVYLE         - 1] = {0x0d, 0x05, 0x10, 0x05, 0x13},
    [SPECIES_SCEPTILE        - 1] = {0x10, 0x04, 0x28, 0x0c, 0x12},
    [SPECIES_TORCHIC         - 1] = {0x17, 0x18, 0x30, 0x15, 0x25},
    [SPECIES_COMBUSKEN       - 1] = {0x20, 0x12, 0x28, 0x1e, 0x20},
    [SPECIES_BLAZIKEN        - 1] = {0x1a, 0x07, 0x28, 0x1d, 0x13},
    [SPECIES_MUDKIP          - 1] = {0x1b, 0x1d, 0x28, 0x19, 0x2c},
    [SPECIES_MARSHTOMP       - 1] = {0x1d, 0x11, 0x30, 0x1c, 0x20},
    [SPECIES_SWAMPERT        - 1] = {0x1b, 0x11, 0x28, 0x1b, 0x23},
    [SPECIES_POOCHYENA       - 1] = {0x14, 0x12, 0x30, 0x0f, 0x20},
    [SPECIES_MIGHTYENA       - 1] = {0x09, 0x0d, 0x28, 0x09, 0x1c},
    [SPECIES_ZIGZAGOON       - 1] = {0x0b, 0x1a, 0x30, 0x09, 0x2b},
    [SPECIES_LINOONE         - 1] = {0x0d, 0x28, 0x18, 0x0b, 0x37},
    [SPECIES_WURMPLE         - 1] = {0x21, 0x17, 0x30, 0x1f, 0x26},
    [SPECIES_SILCOON         - 1] = {0x13, 0x1c, 0x30, 0x11, 0x2a},
    [SPECIES_BEAUTIFLY       - 1] = {0x0f, 0x1b, 0x08, 0x0e, 0x28},
    [SPECIES_CASCOON         - 1] = {0x14, 0x1d, 0x30, 0x11, 0x2c},
    [SPECIES_DUSTOX          - 1] = {0x14, 0x19, 0x08, 0x16, 0x26},
    [SPECIES_LOTAD           - 1] = {0x19, 0x25, 0x28, 0x17, 0x32},
    [SPECIES_LOMBRE          - 1] = {0x22, 0x10, 0x30, 0x29, 0x1d},
    [SPECIES_LUDICOLO        - 1] = {0x1c, 0x0f, 0x28, 0x1b, 0x24},
    [SPECIES_SEEDOT          - 1] = {0x1b, 0x17, 0x30, 0x18, 0x28},
    [SPECIES_NUZLEAF         - 1] = {0x20, 0x0d, 0x30, 0x1a, 0x1d},
    [SPECIES_SHIFTRY         - 1] = {0x32, 0x11, 0x28, 0x2e, 0x23},
    [SPECIES_NINCADA         - 1] = {0x18, 0x1a, 0x30, 0x17, 0x28},
    [SPECIES_NINJASK         - 1] = {0x17, 0x21, 0x00, 0x17, 0x2f},
    [SPECIES_ELECTIVIRE        - 1] = {0x16, 0x19, 0x08, 0x18, 0x2a},
    [SPECIES_TAILLOW         - 1] = {0x17, 0x10, 0x30, 0x14, 0x1e},
    [SPECIES_SWELLOW         - 1] = {0x0c, 0x0a, 0x28, 0x05, 0x16},
    [SPECIES_SHROOMISH       - 1] = {0x1f, 0x16, 0x30, 0x1d, 0x23},
    [SPECIES_BRELOOM         - 1] = {0x25, 0x0c, 0x30, 0x23, 0x19},
    [SPECIES_SPINDA          - 1] = {0x21, 0x16, 0x30, 0x1f, 0x27},
    [SPECIES_WINGULL         - 1] = {0x1a, 0x16, 0x10, 0x15, 0x26},
    [SPECIES_PELIPPER        - 1] = {0x1d, 0x0a, 0x10, 0x09, 0x1b},
    [SPECIES_SURSKIT         - 1] = {0x1d, 0x16, 0x30, 0x1c, 0x25},
    [SPECIES_MASQUERAIN      - 1] = {0x1a, 0x21, 0x08, 0x14, 0x30},
    [SPECIES_WAILMER         - 1] = {0x17, 0x17, 0x30, 0x16, 0x28},
    [SPECIES_WAILORD         - 1] = {0x17, 0x03, 0x30, 0x09, 0x13},
    [SPECIES_SKITTY          - 1] = {0x24, 0x1a, 0x30, 0x22, 0x2a},
    [SPECIES_DELCATTY        - 1] = {0x1e, 0x12, 0x30, 0x1c, 0x21},
    [SPECIES_KECLEON         - 1] = {0x19, 0x10, 0x30, 0x13, 0x1e},
    [SPECIES_BALTOY          - 1] = {0x1d, 0x15, 0x30, 0x1b, 0x22},
    [SPECIES_CLAYDOL         - 1] = {0x1e, 0x0d, 0x28, 0x1d, 0x24},
    [SPECIES_NOSEPASS        - 1] = {0x1f, 0x10, 0x30, 0x15, 0x23},
    [SPECIES_TORKOAL         - 1] = {0x0e, 0x19, 0x28, 0x0a, 0x27},
    [SPECIES_SABLEYE         - 1] = {0x1e, 0x16, 0x30, 0x1d, 0x27},
    [SPECIES_BARBOACH        - 1] = {0x17, 0x12, 0x30, 0x15, 0x1e},
    [SPECIES_WHISCASH        - 1] = {0x18, 0x20, 0x28, 0x17, 0x31},
    [SPECIES_HAPPINY         - 1] = {0x19, 0x0f, 0x30, 0x13, 0x1c},
    [SPECIES_CORPHISH        - 1] = {0x1f, 0x14, 0x30, 0x1d, 0x23},
    [SPECIES_CRAWDAUNT       - 1] = {0x14, 0x0c, 0x28, 0x18, 0x23},
    [SPECIES_FEEBAS          - 1] = {0x18, 0x1e, 0x28, 0x16, 0x2f},
    [SPECIES_MILOTIC         - 1] = {0x20, 0x0c, 0x28, 0x1f, 0x1d},
    [SPECIES_CARVANHA        - 1] = {0x16, 0x19, 0x30, 0x13, 0x22},
    [SPECIES_SHARPEDO        - 1] = {0x19, 0x0c, 0x28, 0x17, 0x27},
    [SPECIES_TRAPINCH        - 1] = {0x29, 0x13, 0x30, 0x17, 0x18},
    [SPECIES_VIBRAVA         - 1] = {0x10, 0x27, 0x20, 0x0e, 0x34},
    [SPECIES_FLYGON          - 1] = {0x22, 0x07, 0x10, 0x21, 0x13},
    [SPECIES_MAKUHITA        - 1] = {0x22, 0x13, 0x30, 0x1c, 0x23},
    [SPECIES_HARIYAMA        - 1] = {0x24, 0x0f, 0x28, 0x26, 0x1c},
    [SPECIES_ELECTRIKE       - 1] = {0x11, 0x18, 0x30, 0x14, 0x27},
    [SPECIES_MANECTRIC       - 1] = {0x2f, 0x18, 0x28, 0x2e, 0x29},
    [SPECIES_NUMEL           - 1] = {0x10, 0x1a, 0x30, 0x0d, 0x2a},
    [SPECIES_CAMERUPT        - 1] = {0x0d, 0x22, 0x28, 0x0e, 0x36},
    [SPECIES_SPHEAL          - 1] = {0x1e, 0x0f, 0x30, 0x18, 0x1f},
    [SPECIES_SEALEO          - 1] = {0x1c, 0x09, 0x30, 0x1a, 0x18},
    [SPECIES_WALREIN         - 1] = {0x19, 0x01, 0x28, 0x10, 0x16},
    [SPECIES_CACNEA          - 1] = {0x1f, 0x17, 0x30, 0x1d, 0x29},
    [SPECIES_CACTURNE        - 1] = {0x1d, 0x0e, 0x28, 0x1d, 0x1b},
    [SPECIES_SNORUNT         - 1] = {0x1e, 0x16, 0x30, 0x1e, 0x26},
    [SPECIES_GLALIE          - 1] = {0x1a, 0x1c, 0x08, 0x1a, 0x31},
    [SPECIES_LUNATONE        - 1] = {0x1c, 0x16, 0x08, 0x19, 0x2c},
    [SPECIES_SOLROCK         - 1] = {0x18, 0x18, 0x10, 0x17, 0x31},
    [SPECIES_AZURILL         - 1] = {0x1b, 0x10, 0x30, 0x18, 0x1f},
    [SPECIES_SPOINK          - 1] = {0x21, 0x14, 0x30, 0x1b, 0x28},
    [SPECIES_GRUMPIG         - 1] = {0x14, 0x10, 0x30, 0x15, 0x20},
    [SPECIES_PLUSLE          - 1] = {0x1c, 0x16, 0x08, 0x1d, 0x25},
    [SPECIES_MINUN           - 1] = {0x21, 0x16, 0x08, 0x1f, 0x26},
    [SPECIES_MAWILE          - 1] = {0x2d, 0x14, 0x30, 0x2f, 0x24},
    [SPECIES_MEDITITE        - 1] = {0x1f, 0x17, 0x30, 0x1e, 0x25},
    [SPECIES_MEDICHAM        - 1] = {0x21, 0x0f, 0x28, 0x1e, 0x1d},
    [SPECIES_SWABLU          - 1] = {0x1b, 0x16, 0x10, 0x17, 0x23},
    [SPECIES_ALTARIA         - 1] = {0x1d, 0x0b, 0x10, 0x1a, 0x1a},
    [SPECIES_TOGEKISS          - 1] = {0x1a, 0x15, 0x30, 0x1b, 0x26},
    [SPECIES_DUSKULL         - 1] = {0x10, 0x18, 0x08, 0x14, 0x2e},
    [SPECIES_DUSCLOPS        - 1] = {0x1c, 0x0f, 0x30, 0x1a, 0x28},
    [SPECIES_ROSELIA         - 1] = {0x1e, 0x11, 0x30, 0x1d, 0x20},
    [SPECIES_SLAKOTH         - 1] = {0x19, 0x1e, 0x30, 0x18, 0x2f},
    [SPECIES_VIGOROTH        - 1] = {0x10, 0x12, 0x28, 0x14, 0x24},
    [SPECIES_SLAKING         - 1] = {0x37, 0x0f, 0x30, 0x29, 0x21},
    [SPECIES_GULPIN          - 1] = {0x1b, 0x18, 0x30, 0x17, 0x26},
    [SPECIES_SWALOT          - 1] = {0x1f, 0x06, 0x30, 0x15, 0x13},
    [SPECIES_TROPIUS         - 1] = {0x18, 0x0a, 0x28, 0x20, 0x18},
    [SPECIES_WHISMUR         - 1] = {0x1f, 0x19, 0x30, 0x1d, 0x29},
    [SPECIES_LOUDRED         - 1] = {0x1c, 0x12, 0x28, 0x22, 0x27},
    [SPECIES_EXPLOUD         - 1] = {0x10, 0x10, 0x28, 0x1a, 0x2a},
    [SPECIES_CLAMPERL        - 1] = {0x20, 0x1a, 0x30, 0x1e, 0x26},
    [SPECIES_HUNTAIL         - 1] = {0x13, 0x1e, 0x28, 0x15, 0x33},
    [SPECIES_GOREBYSS        - 1] = {0x0d, 0x1f, 0x28, 0x03, 0x32},
    [SPECIES_ABSOL           - 1] = {0x2a, 0x11, 0x28, 0x2a, 0x22},
    [SPECIES_SHUPPET         - 1] = {0x16, 0x19, 0x08, 0x17, 0x27},
    [SPECIES_BANETTE         - 1] = {0x1c, 0x14, 0x08, 0x1b, 0x23},
    [SPECIES_SEVIPER         - 1] = {0x0e, 0x0d, 0x30, 0x0b, 0x1e},
    [SPECIES_ZANGOOSE        - 1] = {0x18, 0x0c, 0x28, 0x15, 0x1a},
    [SPECIES_RELICANTH       - 1] = {0x0c, 0x1f, 0x30, 0x09, 0x2d},
    [SPECIES_ARON            - 1] = {0x18, 0x1c, 0x30, 0x1a, 0x2c},
    [SPECIES_LAIRON          - 1] = {0x0b, 0x21, 0x30, 0x12, 0x2f},
    [SPECIES_AGGRON          - 1] = {0x10, 0x0b, 0x28, 0x16, 0x1b},
    [SPECIES_MAGMORTAR        - 1] = {0x1d, 0x18, 0x08, 0x1b, 0x26},
    [SPECIES_VOLBEAT         - 1] = {0x25, 0x15, 0x08, 0x21, 0x25},
    [SPECIES_ILLUMISE        - 1] = {0x20, 0x12, 0x08, 0x1f, 0x20},
    [SPECIES_LILEEP          - 1] = {0x1e, 0x11, 0x30, 0x1f, 0x1e},
    [SPECIES_CRADILY         - 1] = {0x12, 0x16, 0x28, 0x15, 0x28},
    [SPECIES_ANORITH         - 1] = {0x1c, 0x1e, 0x30, 0x1b, 0x2b},
    [SPECIES_ARMALDO         - 1] = {0x15, 0x05, 0x28, 0x14, 0x13},
    [SPECIES_RALTS           - 1] = {0x1f, 0x17, 0x30, 0x20, 0x23},
    [SPECIES_KIRLIA          - 1] = {0x1c, 0x12, 0x30, 0x1f, 0x1e},
    [SPECIES_GARDEVOIR       - 1] = {0x35, 0x07, 0x28, 0x32, 0x14},
    [SPECIES_BAGON           - 1] = {0x17, 0x13, 0x30, 0x16, 0x26},
    [SPECIES_SHELGON         - 1] = {0x19, 0x1b, 0x30, 0x19, 0x2c},
    [SPECIES_SALAMENCE       - 1] = {0x09, 0x11, 0x30, 0x0a, 0x21},
    [SPECIES_BELDUM          - 1] = {0x16, 0x19, 0x08, 0x18, 0x23},
    [SPECIES_METANG          - 1] = {0x22, 0x0f, 0x10, 0x1f, 0x21},
    [SPECIES_METAGROSS       - 1] = {0x24, 0x1b, 0x28, 0x22, 0x2b},
    [SPECIES_MUNCHLAX        - 1] = {0x16, 0x07, 0x28, 0x14, 0x12},
    [SPECIES_LICKILICKY          - 1] = {0x19, 0x0c, 0x28, 0x17, 0x19},
    [SPECIES_MAGNEZONE       - 1] = {0x19, 0x0d, 0x28, 0x19, 0x19},
    [SPECIES_PORYGON_Z          - 1] = {0x0e, 0x19, 0x28, 0x0b, 0x26},
    [SPECIES_GALLADE         - 1] = {0x04, 0x0b, 0x28, 0x0a, 0x19},
    [SPECIES_DUSKNOIR        - 1] = {0x0c, 0x0e, 0x10, 0x0e, 0x1f},
    [SPECIES_RHYPERIOR          - 1] = {0x1e, 0x0c, 0x10, 0x23, 0x19},
    [SPECIES_MAMOSWINE          - 1] = {0x05, 0x0e, 0x10, 0x05, 0x1d},
    [SPECIES_LEAFEON         - 1] = {0x1c, 0x15, 0x08, 0x1e, 0x22},
#if defined(FIRERED)
    [SPECIES_GLACEON          - 1] = {0x1b, 0x08, 0x28, 0x1c, 0x16},
#elif defined(LEAFGREEN)
    [SPECIES_GLACEON          - 1] = {0x1a, 0x09, 0x28, 0x1a, 0x17},
#endif
    [SPECIES_CHIMECHO        - 1] = {0x1d, 0x0c, 0x08, 0x1c, 0x1a},
    [SPECIES_OLD_UNOWN_EMARK - 1] = {0x20, 0x21, 0x08, 0x20, 0x2b},
    [SPECIES_OLD_UNOWN_QMARK - 1] = {0x20, 0x23, 0x08, 0x20, 0x2d}
};

void AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 x, u8 y, const u8 * color, s8 speed, const u8 * str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];
    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];
    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized5(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 letterSpacing, u8 lineSpacing)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = x;
    printer.currentY = y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    AddTextPrinter(&printer, speed, callback);
}

void Menu_PrintFormatIntlPlayerName(u8 windowId, const u8 * src, u16 x, u16 y)
{
    s32 i;

    for (i = 0; gSaveBlock2Ptr->playerName[i] != EOS; i++)
        ;

    StringExpandPlaceholders(gStringVar4, src);
    if (i != 5)
    {
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, x, y, 0xFF, NULL);
    }
    else
    {
        AddTextPrinterParameterized5(windowId, FONT_NORMAL, gStringVar4, x, y, 0xFF, NULL, 0, 0);
    }
}

static void UnusedBlitBitmapRect(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height)
{
    s32 loopSrcY, loopDstY, loopSrcX, loopDstX, xEnd, yEnd, multiplierSrcY, multiplierDstY;
    u16 toOrr;
    u8 *pixelsSrc;
    u8 *pixelsDst;

    if (dst->width - dstX < width)
        xEnd = dst->width - dstX + srcX;
    else
        xEnd = width + srcX;

    if (dst->height - dstY < height)
        yEnd = srcY + dst->height - dstY;
    else
        yEnd = srcY + height;
    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;
    for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
    {
        for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
        {
            pixelsSrc = (u8 *)(src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B));
            pixelsDst = (u8 *)(dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + ((( loopDstY >> 3) * multiplierDstY) << 5) + ((u32)( loopDstY << 0x1d) >> 0x1B));

            if ((u32)pixelsDst & 0x1)
            {
                pixelsDst--;
                if (loopDstX & 0x1)
                {
                    toOrr = *(vu16 *)pixelsDst & 0x0fff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 8);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 12);
                }
                else
                {
                    toOrr = *(vu16 *)pixelsDst & 0xf0ff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 8);
                }
            }
            else
            {
                if (loopDstX & 1)
                {
                    toOrr = *(vu16 *)pixelsDst & 0xff0f;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 0);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 4);
                }
                else
                {
                    toOrr = *(vu16 *)pixelsDst & 0xfff0;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) >> 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) >> 0);
                }
            }
            *(vu16 *)pixelsDst = toOrr;
        }
    }
}

#define tEvA data[0]
#define tEvB data[1]
#define tEvAEnd data[2]
#define tEvBEnd data[3]
#define tEvADelta data[4]
#define tEvBDelta data[5]
#define tEvWhich data[6]
#define tEvStepCount data[8]

void StartBlendTask(u8 eva_start, u8 evb_start, u8 eva_end, u8 evb_end, u8 ev_step, u8 priority)
{
    u8 taskId = CreateTask(Task_SmoothBlendLayers, priority);
    gTasks[taskId].tEvA = eva_start << 8;
    gTasks[taskId].tEvB = evb_start << 8;
    gTasks[taskId].tEvAEnd = eva_end;
    gTasks[taskId].tEvBEnd = evb_end;
    gTasks[taskId].tEvADelta = (eva_end - eva_start) * 256 / ev_step;
    gTasks[taskId].tEvBDelta = (evb_end - evb_start) * 256 / ev_step;
    gTasks[taskId].tEvStepCount = ev_step;
    SetGpuReg(REG_OFFSET_BLDALPHA, (evb_start << 8) | eva_start);
}

bool8 IsBlendTaskActive(void)
{
    return FuncIsActiveTask(Task_SmoothBlendLayers);
}

static void Task_SmoothBlendLayers(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (tEvStepCount != 0)
    {
        if (tEvWhich == 0)
        {
            tEvA += tEvADelta;
            tEvWhich = 1;
        }
        else
        {
            if (--tEvStepCount != 0)
            {
                tEvB += tEvBDelta;
            }
            else
            {
                tEvA = tEvAEnd << 8;
                tEvB = tEvBEnd << 8;
            }
            tEvWhich = 0;
        }
        SetGpuReg(REG_OFFSET_BLDALPHA, (tEvB & ~0xFF) | ((u16)tEvA >> 8));
        if (tEvStepCount == 0)
            DestroyTask(taskId);
    }
}

u8 Menu2_GetMonSpriteAnchorCoord(u16 species, u32 personality, u8 a2)
{
    if (species == SPECIES_UNOWN_B)
    {
        u8 unownLetter = GetUnownLetterByPersonalityLoByte(personality);
        switch (unownLetter)
        {
        case 0:
            break;
        case 26:
            species = SPECIES_OLD_UNOWN_EMARK;
            break;
        case 27:
            species = SPECIES_OLD_UNOWN_QMARK;
            break;
        default:
            species = SPECIES_OLD_UNOWN_B + unownLetter - 1;
            break;
        }
    }
    if (species != SPECIES_NONE && a2 < 5)
    {
        species--;
        if (sMonSpriteAnchorCoords[species][a2] != 0xFF)
            return sMonSpriteAnchorCoords[species][a2];
    }
    return 32;
}

s8 Menu2_GetMonSpriteAnchorCoordMinusx20(u16 species, u32 personality, u8 a2)
{
    return Menu2_GetMonSpriteAnchorCoord(species, personality, a2) - 32;
}
