import re

moves = [
  "POUND",
  "KARATE_CHOP",
  "DOUBLE_SLAP",
  "COMET_PUNCH",
  "MEGA_PUNCH",
  "PAY_DAY",
  "FIRE_PUNCH",
  "ICE_PUNCH",
  "THUNDER_PUNCH",
  "SCRATCH",
  "VICE_GRIP",
  "GUILLOTINE",
  "RAZOR_WIND",
  "SWORDS_DANCE",
  "CUT",
  "GUST",
  "WING_ATTACK",
  "WHIRLWIND",
  "FLY",
  "BIND",
  "SLAM",
  "VINE_WHIP",
  "STOMP",
  "DOUBLE_KICK",
  "MEGA_KICK",
  "JUMP_KICK",
  "ROLLING_KICK",
  "SAND_ATTACK",
  "HEADBUTT",
  "HORN_ATTACK",
  "FURY_ATTACK",
  "HORN_DRILL",
  "TACKLE",
  "BODY_SLAM",
  "WRAP",
  "TAKE_DOWN",
  "THRASH",
  "DOUBLE_EDGE",
  "TAIL_WHIP",
  "POISON_STING",
  "TWINEEDLE",
  "PIN_MISSILE",
  "LEER",
  "BITE",
  "GROWL",
  "ROAR",
  "SING",
  "SUPERSONIC",
  "SONIC_BOOM",
  "DISABLE",
  "ACID",
  "EMBER",
  "FLAMETHROWER",
  "MIST",
  "WATER_GUN",
  "HYDRO_PUMP",
  "SURF",
  "ICE_BEAM",
  "BLIZZARD",
  "PSYBEAM",
  "BUBBLE_BEAM",
  "AURORA_BEAM",
  "HYPER_BEAM",
  "PECK",
  "DRILL_PECK",
  "SUBMISSION",
  "LOW_KICK",
  "COUNTER",
  "SEISMIC_TOSS",
  "STRENGTH",
  "ABSORB",
  "MEGA_DRAIN",
  "LEECH_SEED",
  "GROWTH",
  "RAZOR_LEAF",
  "SOLAR_BEAM",
  "POISON_POWDER",
  "STUN_SPORE",
  "SLEEP_POWDER",
  "PETAL_DANCE",
  "STRING_SHOT",
  "DRAGON_RAGE",
  "FIRE_SPIN",
  "THUNDER_SHOCK",
  "THUNDERBOLT",
  "THUNDER_WAVE",
  "THUNDER",
  "ROCK_THROW",
  "EARTHQUAKE",
  "FISSURE",
  "DIG",
  "TOXIC",
  "CONFUSION",
  "PSYCHIC",
  "HYPNOSIS",
  "MEDITATE",
  "AGILITY",
  "QUICK_ATTACK",
  "RAGE",
  "TELEPORT",
  "NIGHT_SHADE",
  "MIMIC",
  "SCREECH",
  "DOUBLE_TEAM",
  "RECOVER",
  "HARDEN",
  "MINIMIZE",
  "SMOKESCREEN",
  "CONFUSE_RAY",
  "WITHDRAW",
  "DEFENSE_CURL",
  "BARRIER",
  "LIGHT_SCREEN",
  "HAZE",
  "REFLECT",
  "FOCUS_ENERGY",
  "BIDE",
  "METRONOME",
  "MIRROR_MOVE",
  "SELF_DESTRUCT",
  "EGG_BOMB",
  "LICK",
  "SMOG",
  "SLUDGE",
  "BONE_CLUB",
  "FIRE_BLAST",
  "WATERFALL",
  "CLAMP",
  "SWIFT",
  "SKULL_BASH",
  "SPIKE_CANNON",
  "CONSTRICT",
  "AMNESIA",
  "KINESIS",
  "SOFT_BOILED",
  "HI_JUMP_KICK",
  "GLARE",
  "DREAM_EATER",
  "POISON_GAS",
  "BARRAGE",
  "LEECH_LIFE",
  "LOVELY_KISS",
  "SKY_ATTACK",
  "TRANSFORM",
  "BUBBLE",
  "DIZZY_PUNCH",
  "SPORE",
  "FLASH",
  "PSYWAVE",
  "SPLASH",
  "ACID_ARMOR",
  "CRABHAMMER",
  "EXPLOSION",
  "FURY_SWIPES",
  "BONEMERANG",
  "REST",
  "ROCK_SLIDE",
  "HYPER_FANG",
  "SHARPEN",
  "CONVERSION",
  "TRI_ATTACK",
  "SUPER_FANG",
  "SLASH",
  "SUBSTITUTE",
  "STRUGGLE",
  "SKETCH",
  "TRIPLE_KICK",
  "THIEF",
  "SPIDER_WEB",
  "MIND_READER",
  "NIGHTMARE",
  "FLAME_WHEEL",
  "SNORE",
  "CURSE",
  "FLAIL",
  "CONVERSION_2",
  "AEROBLAST",
  "COTTON_SPORE",
  "REVERSAL",
  "SPITE",
  "POWDER_SNOW",
  "PROTECT",
  "MACH_PUNCH",
  "SCARY_FACE",
  "FAINT_ATTACK",
  "SWEET_KISS",
  "BELLY_DRUM",
  "SLUDGE_BOMB",
  "MUD_SLAP",
  "OCTAZOOKA",
  "SPIKES",
  "ZAP_CANNON",
  "FORESIGHT",
  "DESTINY_BOND",
  "PERISH_SONG",
  "ICY_WIND",
  "DETECT",
  "BONE_RUSH",
  "LOCK_ON",
  "OUTRAGE",
  "SANDSTORM",
  "GIGA_DRAIN",
  "ENDURE",
  "CHARM",
  "ROLLOUT",
  "FALSE_SWIPE",
  "SWAGGER",
  "MILK_DRINK",
  "SPARK",
  "FURY_CUTTER",
  "STEEL_WING",
  "MEAN_LOOK",
  "ATTRACT",
  "SLEEP_TALK",
  "HEAL_BELL",
  "RETURN",
  "PRESENT",
  "FRUSTRATION",
  "SAFEGUARD",
  "PAIN_SPLIT",
  "SACRED_FIRE",
  "MAGNITUDE",
  "DYNAMIC_PUNCH",
  "MEGAHORN",
  "DRAGON_BREATH",
  "BATON_PASS",
  "ENCORE",
  "PURSUIT",
  "RAPID_SPIN",
  "SWEET_SCENT",
  "IRON_TAIL",
  "METAL_CLAW",
  "VITAL_THROW",
  "MORNING_SUN",
  "SYNTHESIS",
  "MOONLIGHT",
  "HIDDEN_POWER",
  "CROSS_CHOP",
  "TWISTER",
  "RAIN_DANCE",
  "SUNNY_DAY",
  "CRUNCH",
  "MIRROR_COAT",
  "PSYCH_UP",
  "EXTREME_SPEED",
  "ANCIENT_POWER",
  "SHADOW_BALL",
  "FUTURE_SIGHT",
  "ROCK_SMASH",
  "WHIRLPOOL",
  "BEAT_UP",
  "FAKE_OUT",
  "UPROAR",
  "STOCKPILE",
  "SPIT_UP",
  "SWALLOW",
  "HEAT_WAVE",
  "HAIL",
  "TORMENT",
  "FLATTER",
  "WILL_O_WISP",
  "MEMENTO",
  "FACADE",
  "FOCUS_PUNCH",
  "SMELLING_SALT",
  "FOLLOW_ME",
  "NATURE_POWER",
  "CHARGE",
  "TAUNT",
  "HELPING_HAND",
  "TRICK",
  "ROLE_PLAY",
  "WISH",
  "ASSIST",
  "INGRAIN",
  "SUPERPOWER",
  "MAGIC_COAT",
  "RECYCLE",
  "REVENGE",
  "BRICK_BREAK",
  "YAWN",
  "KNOCK_OFF",
  "ENDEAVOR",
  "ERUPTION",
  "SKILL_SWAP",
  "IMPRISON",
  "REFRESH",
  "GRUDGE",
  "SNATCH",
  "SECRET_POWER",
  "DIVE",
  "ARM_THRUST",
  "CAMOUFLAGE",
  "TAIL_GLOW",
  "LUSTER_PURGE",
  "MIST_BALL",
  "FEATHER_DANCE",
  "TEETER_DANCE",
  "BLAZE_KICK",
  "MUD_SPORT",
  "ICE_BALL",
  "NEEDLE_ARM",
  "SLACK_OFF",
  "HYPER_VOICE",
  "POISON_FANG",
  "CRUSH_CLAW",
  "BLAST_BURN",
  "HYDRO_CANNON",
  "METEOR_MASH",
  "ASTONISH",
  "WEATHER_BALL",
  "AROMATHERAPY",
  "FAKE_TEARS",
  "AIR_CUTTER",
  "OVERHEAT",
  "ODOR_SLEUTH",
  "ROCK_TOMB",
  "SILVER_WIND",
  "METAL_SOUND",
  "GRASS_WHISTLE",
  "TICKLE",
  "COSMIC_POWER",
  "WATER_SPOUT",
  "SIGNAL_BEAM",
  "SHADOW_PUNCH",
  "EXTRASENSORY",
  "SKY_UPPERCUT",
  "SAND_TOMB",
  "SHEER_COLD",
  "MUDDY_WATER",
  "BULLET_SEED",
  "AERIAL_ACE",
  "ICICLE_SPEAR",
  "IRON_DEFENSE",
  "BLOCK",
  "HOWL",
  "DRAGON_CLAW",
  "FRENZY_PLANT",
  "BULK_UP",
  "BOUNCE",
  "MUD_SHOT",
  "POISON_TAIL",
  "COVET",
  "VOLT_TACKLE",
  "MAGICAL_LEAF",
  "WATER_SPORT",
  "CALM_MIND",
  "LEAF_BLADE",
  "DRAGON_DANCE",
  "ROCK_BLAST",
  "SHOCK_WAVE",
  "WATER_PULSE",
  "DOOM_DESIRE",
  "PSYCHO_BOOST",
  "AIR_SLASH",
  "AQUA_JET",
  "AQUA_RING",
  "AQUA_TAIL",
  "ASSURANCE",
  "ATTACK_ORDER",
  "AURA_SPHERE",
  "AVALANCHE",
  "BRAVE_BIRD",
  "BRINE",
  "BUG_BITE",
  "BUG_BUZZ",
  "BULLET_PUNCH",
  "CAPTIVATE",
  "CHARGE_BEAM",
  "CHATTER",
  "CLOSE_COMBAT",
  "COPYCAT",
  "CROSS_POISON",
  "CRUSH_GRIP",
  "DARK_PULSE",
  "DARK_VOID",
  "DEFEND_ORDER",
  "DEFOG",
  "DISCHARGE",
  "DOUBLE_HIT",
  "DRACO_METEOR",
  "DRAGON_PULSE",
  "DRAGON_RUSH",
  "DRAIN_PUNCH",
  "EARTH_POWER",
  "EMBARGO",
  "ENERGY_BALL",
  "FEINT",
  "FIRE_FANG",
  "FLARE_BLITZ",
  "FLASH_CANNON",
  "FLING",
  "FOCUS_BLAST",
  "FORCE_PALM",
  "GASTRO_ACID",
  "GIGA_IMPACT",
  "GRASS_KNOT",
  "GRAVITY",
  "GUARD_SWAP",
  "GUNK_SHOT",
  "GYRO_BALL",
  "HAMMER_ARM",
  "HEAD_SMASH",
  "HEAL_BLOCK",
  "HEAL_ORDER",
  "HEALING_WISH",
  "HEART_SWAP",
  "ICE_FANG",
  "ICE_SHARD",
  "IRON_HEAD",
  "JUDGMENT",
  "LAST_RESORT",
  "LAVA_PLUME",
  "LEAF_STORM",
  "LUCKY_CHANT",
  "LUNAR_DANCE",
  "MAGMA_STORM",
  "MAGNET_BOMB",
  "MAGNET_RISE",
  "ME_FIRST",
  "METAL_BURST",
  "MIRACLE_EYE",
  "MIRROR_SHOT",
  "MUD_BOMB",
  "NASTY_PLOT",
  "NATURAL_GIFT",
  "NIGHT_SLASH",
  "OMINOUS_WIND",
  "PAYBACK",
  "PLUCK",
  "POISON_JAB",
  "POWER_GEM",
  "POWER_SWAP",
  "POWER_TRICK",
  "POWER_WHIP",
  "PSYCHO_CUT",
  "PSYCHO_SHIFT",
  "PUNISHMENT",
  "ROAR_OF_TIME",
  "ROCK_CLIMB",
  "ROCK_POLISH",
  "ROCK_WRECKER",
  "ROOST",
  "SEED_BOMB",
  "SEED_FLARE",
  "SHADOW_CLAW",
  "SHADOW_FORCE",
  "SHADOW_SNEAK",
  "SPACIAL_REND",
  "STEALTH_ROCK",
  "STONE_EDGE",
  "SUCKER_PUNCH",
  "SWITCHEROO",
  "TAILWIND",
  "THUNDER_FANG",
  "TOXIC_SPIKES",
  "TRICK_ROOM",
  "TRUMP_CARD",
  "U_TURN",
  "VACUUM_WAVE",
  "WAKE_UP_SLAP",
  "WOOD_HAMMER",
  "WORRY_SEED",
  "WRING_OUT",
  "X_SCISSOR",
  "ZEN_HEADBUTT",
  "ACUPRESSURE",
]
 
moves_u2l = {}
moves_l2u = {}
for m in moves:
  u = m.strip()
  l = u.replace('_', '').lower()
  moves_l2u[l] = u
  moves_u2l[l] = l
moves_l2u['feintattack'] = 'FAINT_ATTACK'
moves_l2u['smellingsalts'] = 'SMELLING_SALT'
moves_l2u['highjumpkick'] = 'HI_JUMP_KICK'

new_tms_u2l = {}
new_tms_l2u = {}
old_tms_u2l = {}
old_tms_l2u = {}
moves_l2tmu = {}
i = 1
with open('all_tms.txt','r') as in_file:
  for line in in_file:
    u = line.strip()
    l = u.replace('_', '').lower()
    if i < 93:
      old_tms_l2u[l] = u
      old_tms_u2l[u] = l
    else:
      new_tms_l2u[l] = u
      new_tms_u2l[u] = l
    moves_l2tmu[l] = 'TM' + str(i).zfill(3) + '_' + u
    i += 1

regexp = re.compile(r'"4L[4-9][0-9]')
new_tm_ls = {}
lv1_ls = {}
with open('filtered_learnsets.ts','r') as in_file:
  mon = None
  in_learnset = False
  for line in in_file:
    if line[1].isalpha() and line.strip().endswith(': {'):
      mon = line.strip().replace(': {','')
      new_tm_ls[mon] = set()
      lv1_ls[mon] = set()
    elif 'learnset:' in line:
      in_learnset = True
    elif in_learnset:
      if '},' in line:
        in_learnset = False
        continue
    if mon == None or ('"4' not in line and '"3' not in line):
      continue
    sp = line.strip().split(': ["')
    if len(sp) == 0:
      continue
    move = sp[0]
    if move in new_tms_l2u:
      new_tm_ls[mon].add(move)
    elif move not in old_tms_l2u and (('"4L' not in line and '"4M' not in line) or regexp.search(line)):
      lv1_ls[mon].add(move)
    if ('"4L' not in line) and ('"4T' in line or '"4E' in line) and (move in old_tms_l2u):
      # TODO(poke-challenge): Update old TMHM learnsets to include these.
      print(mon + ' is missing old TM: ' + move)


mons = [
  "BULBASAUR",
  "IVYSAUR",
  "VENUSAUR",
  "CHARMANDER",
  "CHARMELEON",
  "CHARIZARD",
  "SQUIRTLE",
  "WARTORTLE",
  "BLASTOISE",
  "CATERPIE",
  "METAPOD",
  "BUTTERFREE",
  "WEEDLE",
  "KAKUNA",
  "BEEDRILL",
  "PIDGEY",
  "PIDGEOTTO",
  "PIDGEOT",
  "RATTATA",
  "RATICATE",
  "SPEAROW",
  "FEAROW",
  "EKANS",
  "ARBOK",
  "PIKACHU",
  "RAICHU",
  "SANDSHREW",
  "SANDSLASH",
  "NIDORAN_F",
  "NIDORINA",
  "NIDOQUEEN",
  "NIDORAN_M",
  "NIDORINO",
  "NIDOKING",
  "CLEFAIRY",
  "CLEFABLE",
  "VULPIX",
  "NINETALES",
  "JIGGLYPUFF",
  "WIGGLYTUFF",
  "ZUBAT",
  "GOLBAT",
  "ODDISH",
  "GLOOM",
  "VILEPLUME",
  "PARAS",
  "PARASECT",
  "VENONAT",
  "VENOMOTH",
  "DIGLETT",
  "DUGTRIO",
  "MEOWTH",
  "PERSIAN",
  "PSYDUCK",
  "GOLDUCK",
  "MANKEY",
  "PRIMEAPE",
  "GROWLITHE",
  "ARCANINE",
  "POLIWAG",
  "POLIWHIRL",
  "POLIWRATH",
  "ABRA",
  "KADABRA",
  "ALAKAZAM",
  "MACHOP",
  "MACHOKE",
  "MACHAMP",
  "BELLSPROUT",
  "WEEPINBELL",
  "VICTREEBEL",
  "TENTACOOL",
  "TENTACRUEL",
  "GEODUDE",
  "GRAVELER",
  "GOLEM",
  "PONYTA",
  "RAPIDASH",
  "SLOWPOKE",
  "SLOWBRO",
  "MAGNEMITE",
  "MAGNETON",
  "FARFETCHD",
  "DODUO",
  "DODRIO",
  "SEEL",
  "DEWGONG",
  "GRIMER",
  "MUK",
  "SHELLDER",
  "CLOYSTER",
  "GASTLY",
  "HAUNTER",
  "GENGAR",
  "ONIX",
  "DROWZEE",
  "HYPNO",
  "KRABBY",
  "KINGLER",
  "VOLTORB",
  "ELECTRODE",
  "EXEGGCUTE",
  "EXEGGUTOR",
  "CUBONE",
  "MAROWAK",
  "HITMONLEE",
  "HITMONCHAN",
  "LICKITUNG",
  "KOFFING",
  "WEEZING",
  "RHYHORN",
  "RHYDON",
  "CHANSEY",
  "TANGELA",
  "KANGASKHAN",
  "HORSEA",
  "SEADRA",
  "GOLDEEN",
  "SEAKING",
  "STARYU",
  "STARMIE",
  "MR_MIME",
  "SCYTHER",
  "JYNX",
  "ELECTABUZZ",
  "MAGMAR",
  "PINSIR",
  "TAUROS",
  "MAGIKARP",
  "GYARADOS",
  "LAPRAS",
  "DITTO",
  "EEVEE",
  "VAPOREON",
  "JOLTEON",
  "FLAREON",
  "PORYGON",
  "OMANYTE",
  "OMASTAR",
  "KABUTO",
  "KABUTOPS",
  "AERODACTYL",
  "SNORLAX",
  "ARTICUNO",
  "ZAPDOS",
  "MOLTRES",
  "DRATINI",
  "DRAGONAIR",
  "DRAGONITE",
  "MIME_JR",
  "BUDEW",
  "CHIKORITA",
  "BAYLEEF",
  "MEGANIUM",
  "CYNDAQUIL",
  "QUILAVA",
  "TYPHLOSION",
  "TOTODILE",
  "CROCONAW",
  "FERALIGATR",
  "SENTRET",
  "FURRET",
  "HOOTHOOT",
  "NOCTOWL",
  "LEDYBA",
  "LEDIAN",
  "SPINARAK",
  "ARIADOS",
  "CROBAT",
  "CHINCHOU",
  "LANTURN",
  "PICHU",
  "CLEFFA",
  "IGGLYBUFF",
  "TOGEPI",
  "TOGETIC",
  "NATU",
  "XATU",
  "MAREEP",
  "FLAAFFY",
  "AMPHAROS",
  "BELLOSSOM",
  "MARILL",
  "AZUMARILL",
  "SUDOWOODO",
  "POLITOED",
  "HOPPIP",
  "SKIPLOOM",
  "JUMPLUFF",
  "AIPOM",
  "SUNKERN",
  "SUNFLORA",
  "YANMA",
  "WOOPER",
  "QUAGSIRE",
  "ESPEON",
  "UMBREON",
  "MURKROW",
  "SLOWKING",
  "MISDREAVUS",
  "WEAVILE",
  "GLISCOR",
  "GIRAFARIG",
  "PINECO",
  "FORRETRESS",
  "DUNSPARCE",
  "GLIGAR",
  "STEELIX",
  "SNUBBULL",
  "GRANBULL",
  "QWILFISH",
  "SCIZOR",
  "SHUCKLE",
  "HERACROSS",
  "SNEASEL",
  "TEDDIURSA",
  "URSARING",
  "SLUGMA",
  "MAGCARGO",
  "SWINUB",
  "PILOSWINE",
  "CORSOLA",
  "REMORAID",
  "OCTILLERY",
  "DELIBIRD",
  "MANTINE",
  "SKARMORY",
  "HOUNDOUR",
  "HOUNDOOM",
  "KINGDRA",
  "PHANPY",
  "DONPHAN",
  "PORYGON2",
  "STANTLER",
  "PROBOPASS",
  "TYROGUE",
  "HITMONTOP",
  "SMOOCHUM",
  "ELEKID",
  "MAGBY",
  "MILTANK",
  "BLISSEY",
  "ROSERADE",
  "TANGROWTH",
  "YANMEGA",
  "LARVITAR",
  "PUPITAR",
  "TYRANITAR",
  "MISMAGIUS",
  "HONCHKROW",
  "FROSLASS",
  "TREECKO",
  "GROVYLE",
  "SCEPTILE",
  "TORCHIC",
  "COMBUSKEN",
  "BLAZIKEN",
  "MUDKIP",
  "MARSHTOMP",
  "SWAMPERT",
  "POOCHYENA",
  "MIGHTYENA",
  "ZIGZAGOON",
  "LINOONE",
  "WURMPLE",
  "SILCOON",
  "BEAUTIFLY",
  "CASCOON",
  "DUSTOX",
  "LOTAD",
  "LOMBRE",
  "LUDICOLO",
  "SEEDOT",
  "NUZLEAF",
  "SHIFTRY",
  "NINCADA",
  "NINJASK",
  "ELECTIVIRE",
  "TAILLOW",
  "SWELLOW",
  "SHROOMISH",
  "BRELOOM",
  "SPINDA",
  "WINGULL",
  "PELIPPER",
  "SURSKIT",
  "MASQUERAIN",
  "WAILMER",
  "WAILORD",
  "SKITTY",
  "DELCATTY",
  "KECLEON",
  "BALTOY",
  "CLAYDOL",
  "NOSEPASS",
  "TORKOAL",
  "SABLEYE",
  "BARBOACH",
  "WHISCASH",
  "HAPPINY",
  "CORPHISH",
  "CRAWDAUNT",
  "FEEBAS",
  "MILOTIC",
  "CARVANHA",
  "SHARPEDO",
  "TRAPINCH",
  "VIBRAVA",
  "FLYGON",
  "MAKUHITA",
  "HARIYAMA",
  "ELECTRIKE",
  "MANECTRIC",
  "NUMEL",
  "CAMERUPT",
  "SPHEAL",
  "SEALEO",
  "WALREIN",
  "CACNEA",
  "CACTURNE",
  "SNORUNT",
  "GLALIE",
  "LUNATONE",
  "SOLROCK",
  "AZURILL",
  "SPOINK",
  "GRUMPIG",
  "PLUSLE",
  "AMBIPOM",
  "MAWILE",
  "MEDITITE",
  "MEDICHAM",
  "SWABLU",
  "ALTARIA",
  "TOGEKISS",
  "DUSKULL",
  "DUSCLOPS",
  "ROSELIA",
  "SLAKOTH",
  "VIGOROTH",
  "SLAKING",
  "GULPIN",
  "SWALOT",
  "TROPIUS",
  "WHISMUR",
  "LOUDRED",
  "EXPLOUD",
  "CLAMPERL",
  "HUNTAIL",
  "GOREBYSS",
  "ABSOL",
  "SHUPPET",
  "BANETTE",
  "SEVIPER",
  "ZANGOOSE",
  "RELICANTH",
  "ARON",
  "LAIRON",
  "AGGRON",
  "MAGMORTAR",
  "VOLBEAT",
  "ILLUMISE",
  "LILEEP",
  "CRADILY",
  "ANORITH",
  "ARMALDO",
  "RALTS",
  "KIRLIA",
  "GARDEVOIR",
  "BAGON",
  "SHELGON",
  "SALAMENCE",
  "BELDUM",
  "METANG",
  "METAGROSS",
  "MUNCHLAX",
  "LICKILICKY",
  "MAGNEZONE",
  "PORYGON_Z",
  "GALLADE",
  "DUSKNOIR",
  "RHYPERIOR",
  "MAMOSWINE",
  "LEAFEON",
  "GLACEON",
  "CHIMECHO",
]

s = '''
// +---------------------------------------------------------------+
// | !!! AUTOGENERATED BY generate_new_tm_and_lv1_learnsets.py !!! |
// +---------------------------------------------------------------+

#define NTMHM_LEARNSET(moves) {(u32)(moves), ((u64)(moves) >> 32)}                                                                                                                                                                             
#define NTMHM(tmhm) ((u64)1 << (ITEM_##tmhm - ITEM_TM093_FIRE_PUNCH))

// This table is similar to the one in tmhm_learnsets.h.
static const u32 sNewTMHMLearnsets[][2] =
{
  [SPECIES_NONE]      = NTMHM_LEARNSET(0),

'''

with open('src/data/pokemon/new_tmhm_learnsets.h', 'w') as c_file:
  for mon in mons:
    moves = new_tm_ls.get(mon.lower().replace('_', ''), set())
    if len(moves) == 0:
      s += '  [SPECIES_' + mon + '] = NTMHM_LEARNSET(0),\n\n'
      continue
    it = iter(moves)
    try:
      move = next(it)
      s += '  [SPECIES_' + mon + '] = NTMHM_LEARNSET(NTMHM(' + moves_l2tmu[move] + ')'
      while True:
        move = next(it)
        s += '\n' + (40*' ') + '| NTMHM(' + moves_l2tmu[move] + ')'
    except StopIteration:
      s += '),\n\n'
  c_file.write(s + '};')

evos = {}
evolving_mons = set()
with open('src/data/pokemon/evolution.h','r') as evo_file:
  for line in evo_file:
    l = line.replace('{', '').replace('}', '').replace('SPECIES_', '').replace('[', '').replace(']', '').replace('=', ',').replace(' ', '').replace('_', '').lower()
    l_split = l.split(',')
    if len(l_split) == 5:
      evos[l_split[3]] = l_split[0]
      evolving_mons.add(l_split[0])
evolving_mons.add(None)
      
s = ''
with open('original_level_up_learnsets.h', 'r') as h_file:
  mon = None
  mon_added = False
  for line in h_file:
    if line.startswith('static const u16 s'):
      mon = line.removeprefix('static const u16 s').removesuffix('LevelUpLearnset[] = {\n').lower()
      mon_added = False
    elif mon_added == False and mon not in evolving_mons:
      for move in lv1_ls.get(mon, []):
        s += '    LEVEL_UP_MOVE( 1, MOVE_' + moves_l2u[move] + '),\n'
      mon_added = True
    s += line

with open('src/data/pokemon/level_up_learnsets.h', 'w') as h_file:
  h_file.write(s)

