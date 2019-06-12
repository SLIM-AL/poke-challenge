#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_player_avatar.h"
#include "help_system.h"
#include "link.h"
#include "overworld.h"
#include "quest_log.h"
#include "save.h"
#include "save_location.h"
#include "strings.h"
#include "constants/maps.h"

EWRAM_DATA u16 gUnknown_203B0EC = 0;
EWRAM_DATA u8 gUnknown_203B0EE = 0;

u8 gUnknown_3005E9C[4];
u16 gUnknown_3005EA0;

bool32 sub_812B27C(const u16 * mapIdxs);
void sub_812B4B8(void);
void sub_812B520(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1);
void sub_812B614(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1);
bool8 sub_812B754(void);
bool8 sub_812B780(u8);
void sub_812BF9C(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1);
void sub_812BF74(const u8 *);

// this file
const u8 *const gUnknown_845B080[] = {
    gUnknown_81B2DF8,
    gUnknown_81B2E1C,
    gUnknown_81B2E2E,
    gUnknown_81B2E48,
    gUnknown_81B2E58,
    gUnknown_81B2E6A
};

const u8 *const gUnknown_845B098[] = {
    gUnknown_81B2E88,
    gUnknown_81B2EC8,
    gUnknown_81B2F00,
    gUnknown_81B2F43,
    gUnknown_81B2F74,
    gUnknown_81B2FA9
};

const u8 *const gUnknown_845B0B0[] = {
    NULL,
    gUnknown_81B3083,
    gUnknown_81B30A9,
    gUnknown_81B30C1,
    gUnknown_81B30DC,
    gUnknown_81B30FC,
    gUnknown_81B311F,
    gUnknown_81B3140,
    gUnknown_81B314F,
    gUnknown_81B3168,
    gUnknown_81B3189,
    gUnknown_81B31AE,
    gUnknown_81B31D3,
    gUnknown_81B31EC,
    gUnknown_81B31FF,
    gUnknown_81B3215,
    gUnknown_81B3226,
    gUnknown_81B3243,
    gUnknown_81B3261,
    gUnknown_81B3276,
    gUnknown_81B3290,
    gUnknown_81B32B6,
    gUnknown_81B32CD,
    gUnknown_81B32E3,
    gUnknown_81B32F9,
    gUnknown_81B330B,
    gUnknown_81B332B,
    gUnknown_81B3344,
    gUnknown_81B335C,
    gUnknown_81B3373,
    gUnknown_81B338C,
    gUnknown_81B33A6,
    gUnknown_81B33CA,
    gUnknown_81B33EA,
    gUnknown_81B3402,
    gUnknown_81B3427,
    gUnknown_81B3440,
    gUnknown_81B3457,
    gUnknown_81B346F,
    gUnknown_81B3481,
    gUnknown_81B349B,
    gUnknown_81B34B7,
    gUnknown_81B34D6,
    gUnknown_81B34F6,
    gUnknown_81B3516
};

const u8 *const gUnknown_845B164[] = {
    NULL,
    gUnknown_81B3525,
    gUnknown_81B35E6,
    gUnknown_81B36EB,
    gUnknown_81B379A,
    gUnknown_81B3849,
    gUnknown_81B3876,
    gUnknown_81B3972,
    gUnknown_81B3A51,
    gUnknown_81B3ACC,
    gUnknown_81B3BB6,
    gUnknown_81B3C99,
    gUnknown_81B3D1B,
    gUnknown_81B3DE3,
    gUnknown_81B3EBC,
    gUnknown_81B3F7F,
    gUnknown_81B406C,
    gUnknown_81B410B,
    gUnknown_81B41D7,
    gUnknown_81B42B3,
    gUnknown_81B439D,
    gUnknown_81B4483,
    gUnknown_81B457C,
    gUnknown_81B4645,
    gUnknown_81B470A,
    gUnknown_81B47F0,
    gUnknown_81B48C6,
    gUnknown_81B497A,
    gUnknown_81B4A72,
    gUnknown_81B4B65,
    gUnknown_81B4C54,
    gUnknown_81B4D26,
    gUnknown_81B4E0B,
    gUnknown_81B4ED8,
    gUnknown_81B4FB2,
    gUnknown_81B4FFD,
    gUnknown_81B50FF,
    gUnknown_81B51B1,
    gUnknown_81B5272,
    gUnknown_81B5325,
    gUnknown_81B5382,
    gUnknown_81B547C,
    gUnknown_81B54E1,
    gUnknown_81B5589,
    gUnknown_81B55F4
};

const u8 *const gUnknown_845B218[] = {
    NULL,
    gUnknown_81B56E3,
    gUnknown_81B56F4,
    gUnknown_81B5705,
    gUnknown_81B5717,
    gUnknown_81B5728,
    gUnknown_81B5737,
    gUnknown_81B5744,
    gUnknown_81B5754,
    gUnknown_81B5767,
    gUnknown_81B577B,
    gUnknown_81B5787,
    gUnknown_81B5795,
    gUnknown_81B57A5,
    gUnknown_81B57B8,
    gUnknown_81B57CF,
    gUnknown_81B57DE,
    gUnknown_81B57EE,
    gUnknown_81B580D,
    gUnknown_81B5824,
    gUnknown_81B5834,
    gUnknown_81B583F,
    gUnknown_81B5850,
    gUnknown_81B5863,
    gUnknown_81B5875,
    gUnknown_81B5884,
    gUnknown_81B5893,
    gUnknown_81B58A4,
    gUnknown_81B58BC,
    gUnknown_81B58D3,
    gUnknown_81B58E5,
    gUnknown_81B58FD,
    gUnknown_81B590E,
    gUnknown_81B591D,
    gUnknown_81B592E,
    gUnknown_81B593E,
    gUnknown_81B5950,
    gUnknown_81B595D,
    gUnknown_81B5974,
    gUnknown_81B5989,
    gUnknown_81B59A7,
    gUnknown_81B59BF,
    gUnknown_81B59D6,
    gUnknown_81B59E8,
    gUnknown_81B59F5,
    gUnknown_81B5A0D,
    gUnknown_81B5A1B,
    gUnknown_81B5A29,
    gUnknown_81B5A37
};

const u8 *const gUnknown_845B2DC[] = {
    NULL,
    gUnknown_81B5A4D,
    gUnknown_81B5B0C,
    gUnknown_81B5B7D,
    gUnknown_81B5C13,
    gUnknown_81B5CDF,
    gUnknown_81B5D87,
    gUnknown_81B5E41,
    gUnknown_81B5F10,
    gUnknown_81B5FA6,
    gUnknown_81B606C,
    gUnknown_81B6140,
    gUnknown_81B6203,
    gUnknown_81B62E4,
    gUnknown_81B6397,
    gUnknown_81B6478,
    gUnknown_81B6525,
    gUnknown_81B65E7,
    gUnknown_81B66BA,
    gUnknown_81B678E,
    gUnknown_81B6883,
    gUnknown_81B68CD,
    gUnknown_81B69B9,
    gUnknown_81B6A9A,
    gUnknown_81B6B6E,
    gUnknown_81B6C4F,
    gUnknown_81B6D4A,
    gUnknown_81B6E02,
    gUnknown_81B6EC1,
    gUnknown_81B6FA8,
    gUnknown_81B7075,
    gUnknown_81B7108,
    gUnknown_81B71EA,
    gUnknown_81B723B,
    gUnknown_81B7319,
    gUnknown_81B73E8,
    gUnknown_81B747E,
    gUnknown_81B752C,
    gUnknown_81B7611,
    gUnknown_81B7692,
    gUnknown_81B771E,
    gUnknown_81B77DD,
    gUnknown_81B7884,
    gUnknown_81B7931,
    gUnknown_81B79CB,
    gUnknown_81B7A60,
    gUnknown_81B7AEE,
    gUnknown_81B7BBE,
    gUnknown_81B7C57
};

const u8 *const gUnknown_845B3A0[] = {
    NULL,
    gUnknown_81B7CC1,
    gUnknown_81B7CC4,
    gUnknown_81B7CD9,
    gUnknown_81B7CDF,
    gUnknown_81B7CE6,
    gUnknown_81B7CEE,
    gUnknown_81B7CF6,
    gUnknown_81B7CFE,
    gUnknown_81B7D04,
    gUnknown_81B7D12,
    gUnknown_81B7D17,
    gUnknown_81B7D1A,
    gUnknown_81B7D1F,
    gUnknown_81B7D27,
    gUnknown_81B7D2D,
    gUnknown_81B7D37,
    gUnknown_81B7D3E,
    gUnknown_81B7D45,
    gUnknown_81B7D48,
    gUnknown_81B7D4E,
    gUnknown_81B7D57,
    gUnknown_81B7D5B,
    gUnknown_81B7D61,
    gUnknown_81B7D6B,
    gUnknown_81B7D76,
    gUnknown_81B7D7E,
    gUnknown_81B7D88,
    gUnknown_81B7D8F,
    gUnknown_81B7D9A,
    gUnknown_81B7DA7,
    gUnknown_81B7DB4,
    gUnknown_81B7DBA,
    gUnknown_81B7DC6,
    gUnknown_81B7DCC,
    gUnknown_81B7DD3,
    gUnknown_81B7DD6,
    gUnknown_81B7DD9,
    gUnknown_81B7DE1,
    gUnknown_81B7DEB,
    gUnknown_81B7DFA,
    gUnknown_81B7E02,
    gUnknown_81B7E09,
    gUnknown_81B7E0F
};

const u8 *const gUnknown_845B450[] = {
    NULL,
    gUnknown_81B7E16,
    gUnknown_81B7F0A,
    gUnknown_81B800A,
    gUnknown_81B80EC,
    gUnknown_81B81C2,
    gUnknown_81B8256,
    gUnknown_81B8348,
    gUnknown_81B83EF,
    gUnknown_81B847B,
    gUnknown_81B8550,
    gUnknown_81B8647,
    gUnknown_81B86E2,
    gUnknown_81B87B8,
    gUnknown_81B8897,
    gUnknown_81B8924,
    gUnknown_81B8A04,
    gUnknown_81B8A84,
    gUnknown_81B8B62,
    gUnknown_81B8C18,
    gUnknown_81B8C94,
    gUnknown_81B8D1D,
    gUnknown_81B8DD4,
    gUnknown_81B8E67,
    gUnknown_81B8F4D,
    gUnknown_81B901B,
    gUnknown_81B90A7,
    gUnknown_81B90E8,
    gUnknown_81B9170,
    gUnknown_81B91C2,
    gUnknown_81B91F9,
    gUnknown_81B92B8,
    gUnknown_81B92ED,
    gUnknown_81B93D8,
    gUnknown_81B9439,
    gUnknown_81B9497,
    gUnknown_81B9560,
    gUnknown_81B9656,
    gUnknown_81B9749,
    gUnknown_81B984F,
    gUnknown_81B991C,
    gUnknown_81B99C4,
    gUnknown_81B9AA2,
    gUnknown_81B9B2F
};

const u8 *const gUnknown_845B500[] = {
    NULL,
    gUnknown_81B9BB7,
    gUnknown_81B9BC7,
    gUnknown_81B9BD0,
    gUnknown_81B9BE1,
    gUnknown_81B9BF5,
    gUnknown_81B9C09,
    gUnknown_81B9C1D
};

const u8 *const gUnknown_845B520[] = {
    NULL,
    gUnknown_81B9C2F,
    gUnknown_81B9D04,
    gUnknown_81B9DC5,
    gUnknown_81B9E75,
    gUnknown_81B9F09,
    gUnknown_81B9FCE,
    gUnknown_81BA027
};

const u8 *const gUnknown_845B540[] = {
    NULL,
    gUnknown_81BA0F1,
    gUnknown_81BA10D,
    gUnknown_81BA121,
    gUnknown_81BA138,
    gUnknown_81BA14C,
    gUnknown_81BA163,
    gUnknown_81BA17A,
    gUnknown_81BA194,
    gUnknown_81BA1AC,
    gUnknown_81BA1C7,
    gUnknown_81BA1DC,
    gUnknown_81BA1F4,
    gUnknown_81BA209,
    gUnknown_81BA221,
    gUnknown_81BA234,
    gUnknown_81BA24A,
    gUnknown_81BA260,
    gUnknown_81BA279,
    gUnknown_81BA291,
    gUnknown_81BA2AC,
    gUnknown_81BA2C2,
    gUnknown_81BA2DB,
    gUnknown_81BA2F1,
    gUnknown_81BA30A,
    gUnknown_81BA320,
    gUnknown_81BA339,
    gUnknown_81BA34E,
    gUnknown_81BA366,
    gUnknown_81BA37C,
    gUnknown_81BA395,
    gUnknown_81BA3A9,
    gUnknown_81BA3C0,
    gUnknown_81BA3D5,
    gUnknown_81BA3ED,
    gUnknown_81BA400
};

const u8 *const gUnknown_845B5D0[] = {
    NULL,
    gUnknown_81BA416,
    gUnknown_81BA4E6,
    gUnknown_81BA539,
    gUnknown_81BA595,
    gUnknown_81BA5F2,
    gUnknown_81BA66F,
    gUnknown_81BA6C9,
    gUnknown_81BA71F,
    gUnknown_81BA796,
    gUnknown_81BA7E9,
    gUnknown_81BA862,
    gUnknown_81BA8D3,
    gUnknown_81BA92A,
    gUnknown_81BA98D,
    gUnknown_81BA9F1,
    gUnknown_81BAA44,
    gUnknown_81BAAB6,
    gUnknown_81BAB18,
    gUnknown_81BAB7A,
    gUnknown_81BABCC,
    gUnknown_81BAC29,
    gUnknown_81BAC89,
    gUnknown_81BACC4,
    gUnknown_81BAD20,
    gUnknown_81BAD60,
    gUnknown_81BADA2,
    gUnknown_81BADF7,
    gUnknown_81BAEA8,
    gUnknown_81BAF01,
    gUnknown_81BAF6B,
    gUnknown_81BAFCA,
    gUnknown_81BB02E,
    gUnknown_81BB084,
    gUnknown_81BB0DF,
    gUnknown_81BB156
};


const u8 gUnknown_845B660[] = {
    0x01, 0x02, 0x03, 0xff
};

const u8 gUnknown_845B664[] = {
    0x01, 0x02, 0x03, 0xff
};

const u8 gUnknown_845B668[] = {
    0x13, 0xff
};

const u8 gUnknown_845B66A[] = {
    0x01, 0x02, 0x03, 0xff
};

const u8 gUnknown_845B66E[] = {
    0x01, 0x25, 0xff
};

const u8 gUnknown_845B671[] = {
    0x02, 0x03, 0x04, 0x05, 0x11, 0xff
};

const u8 gUnknown_845B677[] = {
    0x09, 0x01, 0xff
};

const u8 gUnknown_845B67A[] = {
    0x02, 0x03, 0xff
};

const u8 gUnknown_845B67D[] = {
    0x09, 0x0a, 0x0b, 0x11, 0x0c, 0x10, 0xff
};

const u8 gUnknown_845B684[] = {
    0x09, 0x01, 0x04, 0x05, 0x06, 0x07, 0x08, 0x02, 0x0d, 0xff
};

const u8 gUnknown_845B68E[] = {
    0x09, 0x03, 0x0a, 0x0f, 0x12, 0x13, 0x14, 0xff
};

const u8 gUnknown_845B696[] = {
    0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x12, 0xff
};

const u8 gUnknown_845B6A1[] = {
    0x16, 0x17, 0x18, 0xff
};

const u8 gUnknown_845B6A5[] = {
    0x0a, 0xff
};

const u8 gUnknown_845B6A7[] = {
    0x11, 0x0e, 0x19, 0x1a, 0x1b, 0xff
};

const u8 gUnknown_845B6AD[] = {
    0x0a, 0xff
};

const u8 gUnknown_845B6AF[] = {
    0x0b, 0xff
};

const u8 gUnknown_845B6B1[] = {
    0x2b, 0x19, 0x1a, 0xff
};

const u8 gUnknown_845B6B5[] = {
    0x0c, 0xff
};

const u8 gUnknown_845B6B7[] = {
    0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0xff
};

const u8 gUnknown_845B6BF[] = {
    0x02, 0x03, 0x04, 0xff
};

const u8 gUnknown_845B6C3[] = {
    0x01, 0x02, 0x03, 0x07, 0xff
};

const u8 gUnknown_845B6C8[] = {
    0x02, 0x04, 0x05, 0x09, 0x25, 0xff
};

const u8 gUnknown_845B6CE[] = {
    0x1f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B6E2[] = {
    0x09, 0x01, 0x02, 0x03, 0x0a, 0x28, 0xff
};

const u8 gUnknown_845B6E9[] = {
    0x02, 0x05, 0x06, 0x0a, 0x23, 0x24, 0x09, 0x25, 0xff
};

const u8 gUnknown_845B6F2[] = {
    0x1f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x0a, 0x0b, 0x0c, 0x11, 0x14, 0xff
};

const u8 gUnknown_845B707[] = {
    0x09, 0x01, 0x02, 0x03, 0x0a, 0x28, 0xff
};

const u8 gUnknown_845B70E[] = {
    0x03, 0x07, 0x04, 0x05, 0x06, 0xff
};

const u8 gUnknown_845B714[] = {
    0x02, 0x05, 0x06, 0x0a, 0x23, 0x24, 0x09, 0x25, 0xff
};

const u8 gUnknown_845B71D[] = {
    0x1f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B731[] = {
    0x09, 0x01, 0x02, 0x03, 0x0a, 0x0c, 0x0e, 0x16, 0x17, 0x18, 0x15, 0xff
};

const u8 gUnknown_845B73D[] = {
    0x06, 0x0a, 0x23, 0x24, 0x09, 0x25, 0xff
};

const u8 gUnknown_845B744[] = {
    0x1f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B758[] = {
    0x09, 0x01, 0x02, 0x03, 0x0a, 0x15, 0xff
};

const u8 gUnknown_845B75F[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff
};

const u8 gUnknown_845B783[] = {
    0x02, 0x0a, 0x04, 0x05, 0x06, 0x07, 0x0d, 0x27, 0x08, 0x0b, 0x21, 0x23, 0x24, 0x2c, 0x09, 0x0e, 0x16, 0x17, 0x0f, 0x10, 0x11, 0x1a, 0x15, 0x1f, 0x20, 0x12, 0x13, 0x14, 0x18, 0x19, 0x1b, 0x1e, 0x1c, 0x28, 0x25, 0xff
};

const u8 gUnknown_845B7A7[] = {
    0x1f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x2c, 0x09, 0x0d, 0x0e, 0x0f, 0x10, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B7BB[] = {
    0x09, 0x01, 0x02, 0x0a, 0x0b, 0x0c, 0x0d, 0x15, 0xff
};

const u8 gUnknown_845B7C4[] = {
    0x02, 0x0a, 0x04, 0x05, 0x06, 0x07, 0x0d, 0x27, 0x08, 0x0b, 0x21, 0x23, 0x24, 0x2c, 0x09, 0x0e, 0x16, 0x17, 0x0f, 0x10, 0x11, 0x1a, 0x15, 0x1f, 0x20, 0x12, 0x13, 0x14, 0x18, 0x19, 0x1b, 0x1e, 0x1c, 0x28, 0x25, 0xff
};

const u8 gUnknown_845B7E8[] = {
    0x1f, 0x01, 0x02, 0x06, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B7F1[] = {
    0x09, 0x01, 0x02, 0x0a, 0x0b, 0x0c, 0x0d, 0x15, 0x28, 0xff
};

const u8 gUnknown_845B7FB[] = {
    0x0a, 0x07, 0x0d, 0x27, 0x08, 0x0b, 0x21, 0x23, 0x24, 0x2c, 0x09, 0x0e, 0x16, 0x0f, 0x10, 0x11, 0x1a, 0x15, 0x1f, 0x20, 0x12, 0x13, 0x14, 0x18, 0x19, 0x1b, 0x1e, 0x1c, 0x28, 0x25, 0xff
};

const u8 gUnknown_845B81A[] = {
    0x1f, 0x01, 0x02, 0x06, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B823[] = {
    0x09, 0x01, 0x02, 0x0a, 0x0b, 0x0c, 0x0d, 0x15, 0xff
};

const u8 gUnknown_845B82C[] = {
    0x07, 0x27, 0x08, 0x2c, 0x15, 0x1f, 0x20, 0x12, 0x13, 0x14, 0x18, 0x19, 0x1b, 0x1e, 0x1c, 0x28, 0x25, 0xff
};

const u8 gUnknown_845B83E[] = {
    0x1f, 0x01, 0x02, 0x06, 0x0a, 0x0b, 0x0c, 0x11, 0xff
};

const u8 gUnknown_845B847[] = {
    0x09, 0x01, 0x02, 0x0a, 0x0b, 0x0c, 0x0d, 0x15, 0xff
};

const u8 gUnknown_845B850[] = {
    0x0f, 0x1b, 0x1d, 0x11, 0x12, 0x15, 0x17, 0x16, 0x1f, 0x20, 0x13, 0x14, 0xff
};

const u8 gUnknown_845B85D[] = {
    0x20, 0x21, 0x22, 0x23, 0x24, 0x07, 0x09, 0x2b, 0xff
};

const u8 gUnknown_845B866[] = {
    0x09, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0d, 0x0f, 0x12, 0x13, 0x14, 0x27, 0x15, 0xff
};

const u8 gUnknown_845B878[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff
};

const u8 gUnknown_845B89C[] = {
    0x0f, 0x1b, 0x1d, 0x11, 0x12, 0x16, 0x1f, 0x20, 0x13, 0x14, 0xff
};

const u8 gUnknown_845B8A7[] = {
    0x20, 0x21, 0x22, 0x23, 0x24, 0x07, 0x2b, 0xff
};

const u8 gUnknown_845B8AF[] = {
    0x09, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0d, 0x0f, 0x12, 0x13, 0x14, 0x27, 0x15, 0xff
};

const u8 gUnknown_845B8C1[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff
};

const u8 gUnknown_845B8E5[] = {
    0x0f, 0x1b, 0x1d, 0x11, 0x12, 0x16, 0x1f, 0x20, 0x13, 0x14, 0xff
};

const u8 gUnknown_845B8F0[] = {
    0x20, 0x21, 0x22, 0x23, 0x24, 0x07, 0x2b, 0xff
};

const u8 gUnknown_845B8F8[] = {
    0x09, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0d, 0x0f, 0x12, 0x13, 0x14, 0x27, 0x15, 0xff
};

const u8 gUnknown_845B90A[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff
};

const u8 gUnknown_845B92E[] = {
    0x29, 0x2a, 0x2b, 0xff
};

const u8 gUnknown_845B932[] = {
    0x2d, 0x2e, 0x2f, 0x2b, 0xff
};

const u8 gUnknown_845B937[] = {
    0x09, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0d, 0x0f, 0x12, 0x13, 0x14, 0xff
};

const u8 gUnknown_845B947[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff
};

const u8 gUnknown_845B96B[] = {
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x30, 0xff
};

const u8 gUnknown_845B978[] = {
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x30, 0xff
};

const u8 gUnknown_845B985[] = {
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x30, 0xff
};

const u8 gUnknown_845B992[] = {
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x30, 0xff
};

const u8 gUnknown_845B99F[] = {
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x30, 0xff
};

const u8 gUnknown_845B9AC[] = {
    0x26, 0x27, 0x28, 0x29, 0x2a, 0xff
};

const u8 gUnknown_845B9B2[] = {
    0x26, 0x27, 0x28, 0x29, 0x2a, 0xff
};

const u8 gUnknown_845B9B8[] = {
    0x26, 0x27, 0x28, 0x29, 0x2a, 0xff
};

const u8 gUnknown_845B9BE[] = {
    0x09, 0x01, 0x02, 0x03, 0x23, 0x25, 0x24, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0c, 0x0d, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x27, 0x15, 0x26, 0x16, 0x17, 0x18, 0x1a, 0x0e, 0x1b, 0xff
};

const u8 *const gUnknown_845B9E0[] = {
    NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, gUnknown_845B660, NULL,
    NULL, NULL, NULL, gUnknown_845B664, NULL,
    NULL, gUnknown_845B668, NULL, gUnknown_845B66A, NULL,
    NULL, gUnknown_845B66E, NULL, NULL, NULL,
    NULL, gUnknown_845B671, gUnknown_845B677, NULL, NULL,
    NULL, gUnknown_845B67A, gUnknown_845B67D, NULL, NULL,
    NULL, NULL, gUnknown_845B684, NULL, NULL,
    NULL, NULL, gUnknown_845B68E, NULL, NULL,
    NULL, gUnknown_845B696, gUnknown_845B6A1, NULL, NULL,
    NULL, gUnknown_845B6A5, gUnknown_845B6A7, NULL, NULL,
    NULL, gUnknown_845B6AD, NULL, NULL, NULL,
    NULL, gUnknown_845B6AF, gUnknown_845B6B1, NULL, NULL,
    NULL, gUnknown_845B6B5, gUnknown_845B6B7, NULL, NULL,
    gUnknown_845B6BF, NULL, NULL, gUnknown_845B6C3, NULL,
    gUnknown_845B6C8, gUnknown_845B6CE, gUnknown_845B6E2, NULL, NULL,
    gUnknown_845B6E9, gUnknown_845B6F2, gUnknown_845B707, gUnknown_845B70E, NULL,
    gUnknown_845B714, gUnknown_845B71D, gUnknown_845B731, NULL, NULL,
    gUnknown_845B73D, gUnknown_845B744, gUnknown_845B758, NULL, gUnknown_845B75F,
    gUnknown_845B783, gUnknown_845B7A7, gUnknown_845B7BB, NULL, NULL,
    gUnknown_845B7C4, gUnknown_845B7E8, gUnknown_845B7F1, NULL, NULL,
    gUnknown_845B7FB, gUnknown_845B81A, gUnknown_845B823, NULL, NULL,
    gUnknown_845B82C, gUnknown_845B83E, gUnknown_845B847, NULL, NULL,
    gUnknown_845B850, gUnknown_845B85D, gUnknown_845B866, NULL, gUnknown_845B878,
    gUnknown_845B89C, gUnknown_845B8A7, gUnknown_845B8AF, NULL, gUnknown_845B8C1,
    gUnknown_845B8E5, gUnknown_845B8F0, gUnknown_845B8F8, NULL, gUnknown_845B90A,
    gUnknown_845B92E, gUnknown_845B932, gUnknown_845B937, NULL, gUnknown_845B947,
    NULL, gUnknown_845B96B, NULL, NULL, NULL,
    NULL, gUnknown_845B978, NULL, NULL, NULL,
    NULL, gUnknown_845B985, NULL, NULL, NULL,
    NULL, gUnknown_845B992, NULL, NULL, NULL,
    NULL, gUnknown_845B99F, NULL, NULL, NULL,
    NULL, gUnknown_845B9AC, NULL, NULL, NULL,
    NULL, gUnknown_845B9B2, NULL, NULL, NULL,
    NULL, gUnknown_845B9B8, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL
};

const u16 unref_845BCB0[] = INCBIN_U16("graphics/help_system/unk_845BCB0.bin");

const u8 gUnknown_845C4B0[] = {
    3, 0, 1, 2, 4, 5
};

const u8 gUnknown_845C4B6[][6] = {
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

const u16 gUnknown_845C594[] = {
    MAP_VIRIDIAN_CITY_MART,
    MAP_PEWTER_CITY_MART,
    MAP_CERULEAN_CITY_MART,
    MAP_LAVENDER_TOWN_MART,
    MAP_VERMILION_CITY_MART,
    MAP_CELADON_CITY_DEPARTMENT_STORE_1F,
    MAP_CELADON_CITY_DEPARTMENT_STORE_2F,
    MAP_CELADON_CITY_DEPARTMENT_STORE_3F,
    MAP_CELADON_CITY_DEPARTMENT_STORE_4F,
    MAP_CELADON_CITY_DEPARTMENT_STORE_5F,
    MAP_CELADON_CITY_DEPARTMENT_STORE_ROOF,
    MAP_CELADON_CITY_DEPARTMENT_STORE_ELEVATOR,
    MAP_FUCHSIA_CITY_MART,
    MAP_CINNABAR_ISLAND_MART,
    MAP_SAFFRON_CITY_MART,
    MAP_THREE_ISLAND_MART,
    MAP_FOUR_ISLAND_MART,
    MAP_SEVEN_ISLAND_MART,
    MAP_SIX_ISLAND_MART,
    MAP_UNDEFINED
};

const u16 gUnknown_845C5BC[] = {
    MAP_PEWTER_CITY_GYM,
    MAP_CERULEAN_CITY_GYM,
    MAP_VERMILION_CITY_GYM,
    MAP_CELADON_CITY_GYM,
    MAP_FUCHSIA_CITY_GYM,
    MAP_SAFFRON_CITY_GYM,
    MAP_CINNABAR_ISLAND_GYM,
    MAP_VIRIDIAN_CITY_GYM,
    MAP_UNDEFINED
};

const u8 gUnknown_845C5CE[][3] = {
    { MAP_GROUP(VIRIDIAN_FOREST), MAP_NUM(VIRIDIAN_FOREST), 1 },
    { MAP_GROUP(MT_MOON_1F), MAP_NUM(MT_MOON_1F), 3 },
    { MAP_GROUP(ROCK_TUNNEL_1F), MAP_NUM(ROCK_TUNNEL_1F), 2 },
    { MAP_GROUP(DIGLETTS_CAVE_NORTH_ENTRANCE), MAP_NUM(DIGLETTS_CAVE_NORTH_ENTRANCE), 3 },
    { MAP_GROUP(SEAFOAM_ISLANDS_1F), MAP_NUM(SEAFOAM_ISLANDS_1F), 5 },
    { MAP_GROUP(VICTORY_ROAD_1F), MAP_NUM(VICTORY_ROAD_1F), 3 },
    { MAP_GROUP(CERULEAN_CAVE_1F), MAP_NUM(CERULEAN_CAVE_1F), 3 },
    { MAP_GROUP(MT_EMBER_RUBY_PATH_B4F), MAP_NUM(MT_EMBER_RUBY_PATH_B4F), 1 },
    { MAP_GROUP(MT_EMBER_SUMMIT_PATH_1F), MAP_NUM(MT_EMBER_SUMMIT_PATH_1F), 3 },
    { MAP_GROUP(MT_EMBER_RUBY_PATH_B5F), MAP_NUM(MT_EMBER_RUBY_PATH_B5F), 7 },
    { MAP_GROUP(THREE_ISLAND_BERRY_FOREST), MAP_NUM(THREE_ISLAND_BERRY_FOREST), 1 },
    { MAP_GROUP(SIX_ISLAND_PATTERN_BUSH), MAP_NUM(SIX_ISLAND_PATTERN_BUSH), 1 },
    { MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ENTRANCE), MAP_NUM(FIVE_ISLAND_LOST_CAVE_ENTRANCE), 15 },
    { MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE), MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE), 4 },
    { MAP_GROUP(SIX_ISLAND_ALTERING_CAVE), MAP_NUM(SIX_ISLAND_ALTERING_CAVE), 1 },
    { MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER), MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER), 7 }
};

void sub_812B1E0(u8 a0)
{
    gUnknown_203B0EC = a0;
}

void HelpSystem_SetSomeVariable2(u8 a0)
{
    switch (gUnknown_203B0EC)
    {
    case 23:
    case 24:
    case 25:
    case 26:
        if (a0 == 9 || a0 == 5 || a0 == 6 || a0 == 7 || a0 == 8)
            break;
        // fallthrough
    default:
        gUnknown_203B0EC = a0;
        break;
    }
}

void sub_812B220(void)
{
    gUnknown_203B0EC = gSpecialVar_0x8004;
}

void sub_812B234(void)
{
    gUnknown_3005EA0 = gUnknown_203B0EC;
}

void sub_812B248(void)
{
    gUnknown_203B0EC = gUnknown_3005EA0;
}

bool32 sub_812B25C(void)
{
    return sub_812B27C(gUnknown_845C594);
}

bool32 sub_812B26C(void)
{
    return sub_812B27C(gUnknown_845C5BC);
}

bool32 sub_812B27C(const u16 * mapIdxs)
{
    u16 mapIdx = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;
    s32 i;

    for (i = 0; mapIdxs[i] != MAP_UNDEFINED; i++)
    {
        if (mapIdxs[i] == mapIdx)
            return TRUE;
    }

    return FALSE;
}

bool8 sub_812B2C4(void)
{
    u8 i, j;

    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < gUnknown_845C5CE[i][2]; j++)
        {
            if (
                   gUnknown_845C5CE[i][0] == gSaveBlock1Ptr->location.mapGroup
                && gUnknown_845C5CE[i][1] + j == gSaveBlock1Ptr->location.mapNum
                && (i != 15 || FlagGet(FLAG_0x849) == TRUE)
            )
                return TRUE;
        }
    }

    return FALSE;
}

void sub_812B35C(void)
{
    sub_812B4B8();
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        HelpSystem_SetSomeVariable2(0x16);
    else if (sub_812B2C4())
        HelpSystem_SetSomeVariable2(0x15);
    else if (is_light_level_8_or_9(gMapHeader.mapType))
    {
        if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PALLET_TOWN_PLAYERS_HOUSE_1F) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN_PLAYERS_HOUSE_1F)) || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PALLET_TOWN_PLAYERS_HOUSE_2F) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN_PLAYERS_HOUSE_2F)))
            HelpSystem_SetSomeVariable2(0x0E);
        else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PALLET_TOWN_PROFESSOR_OAKS_LAB) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN_PROFESSOR_OAKS_LAB))
            HelpSystem_SetSomeVariable2(0x0F);
        else if (IsCurMapPokeCenter() == TRUE)
            HelpSystem_SetSomeVariable2(0x10);
        else if (sub_812B25C() == TRUE)
            HelpSystem_SetSomeVariable2(0x11);
        else if (sub_812B26C() == TRUE)
            HelpSystem_SetSomeVariable2(0x12);
        else
            HelpSystem_SetSomeVariable2(0x13);
    }
    else
        HelpSystem_SetSomeVariable2(0x14);
}

bool8 sub_812B40C(void)
{
    if (gUnknown_203B0EE == 1)
        return FALSE;

    if (gSaveFileStatus != SAVE_STATUS_EMPTY && gSaveFileStatus != SAVE_STATUS_INVALID && FlagGet(FLAG_0x83C))
        return FALSE;

    FlagSet(FLAG_0x83C);
    gUnknown_203B0EE = 1;
    return TRUE;
}

bool8 sub_812B45C(void)
{
    if (gReceivedRemoteLinkPlayers == 1)
        return FALSE;
    return TRUE;
}

void sub_812B478(void)
{
    gUnknown_3005ECC = 0;
}

void sub_812B484(void)
{
    if (gUnknown_203ADFA != 2 && gUnknown_203ADFA != 3)
    {
        gUnknown_3005ECC = 1;
        sub_812B4B8();
    }
}

void sub_812B4AC(void)
{
    gUnknown_203F175 = 1;
}

void sub_812B4B8(void)
{
    gUnknown_203F175 = 0;
}

void sub_812B4C4(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1)
{
    a0->sub.field_00 = a1;
    a0->sub.field_04 = 1;
    a0->sub.field_06 = 1;
    a0->sub.field_08 = 1;
    a0->sub.field_09 = 4;
}

void sub_812B4D8(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1)
{
    sub_812B4C4(a0, a1);
    sub_812B520(a0, a1);
    sub_812BF74(gUnknown_841DFAC);
    sub_813C64C(a0, 0, gUnknown_3005E9C[2]);
    sub_812BF9C(a0, a1);
    sub_813BDA4(1);
    sub_813BD5C(1);
}

void sub_812B520(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1)
{
    u8 i;
    u8 r4 = 0;
    for (i = 0; i < 6; i++)
    {
        if (gUnknown_845C4B6[gUnknown_203B0EC][gUnknown_845C4B0[i]] == 1)
        {
            a1[r4].label = gUnknown_845B080[gUnknown_845C4B0[i]];
            a1[r4].index = gUnknown_845C4B0[i];
            r4++;
        }
    }
    a1[r4 - 1].index = -2;
    a0->sub.field_04 = r4;
    a0->sub.field_06 = r4;
    a0->sub.field_08 = 0;
}

void sub_812B5A8(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1)
{
    sub_813BDE8(0);
    sub_813BFC0(0);
    sub_813BE78(1);
    sub_812B4C4(a0, a1);
    sub_812B614(a0, a1);
    sub_812BF74(gUnknown_841DFC9);
    sub_813C64C(a0, a0->field_0C, a0->field_0D);
    sub_813C4CC(gUnknown_845B080[gUnknown_3005E9C[1]], 0, 0);
    sub_813BDA4(1);
    sub_813BD5C(1);
}

void sub_812B614(struct HelpSystemStruct_203F190 * a0, struct ListMenuItem * a1)
{
    u8 r6 = 0;
    const u8 * r3 = gUnknown_845B9E0[gUnknown_203B0EC * 5 + gUnknown_3005E9C[1]];
    u8 i;
    for (i = 0; r3[i] != 0xFF; i++)
    {
        if (sub_812B780(r3[i]) == TRUE)
        {
            if (gUnknown_3005E9C[1] == 0)
                a1[r6].label = gUnknown_845B0B0[r3[i]];
            else if (gUnknown_3005E9C[1] == 1)
                a1[r6].label = gUnknown_845B218[r3[i]];
            else if (gUnknown_3005E9C[1] == 2)
                a1[r6].label = gUnknown_845B3A0[r3[i]];
            else if (gUnknown_3005E9C[1] == 3)
                a1[r6].label = gUnknown_845B500[r3[i]];
            else
                a1[r6].label = gUnknown_845B540[r3[i]];
            a1[r6].index = r3[i];
            r6++;
        }
    }
    if (sub_812B754() == TRUE)
    {
        for (i = 0, r3 = gUnknown_845B9BE; r3[i] != 0xFF; i++)
        {
            a1[r6].label = gUnknown_845B3A0[r3[i]];
            a1[r6].index = r3[i];
            r6++;
        }
    }
    a1[r6].label = gUnknown_81B2E6F;
    a1[r6].index = -2;
    r6++;
    a0->sub.field_04 = r6;
    a0->sub.field_06 = 7;
    a0->sub.field_08 = 0;
    a0->sub.field_09 = 21;
}

bool8 sub_812B754(void)
{
    if (FlagGet(FLAG_0x4B0) == TRUE && gUnknown_3005E9C[1] == 2)
        return TRUE;
    return FALSE;
}
