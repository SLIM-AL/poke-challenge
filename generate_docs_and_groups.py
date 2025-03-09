# import markdown

pokes = [
  ('NONE', 'NULL'),

  ('BULBASAUR', 'GrassStarter1'),
  ('IVYSAUR', 'GrassStarter2'),
  ('VENUSAUR', 'GrassStarter3'),

  ('CHARMANDER', 'FireStarter1'),
  ('CHARMELEON', 'FireStarter2'),
  ('CHARIZARD', 'FireStarter3'),

  ('SQUIRTLE', 'WaterStarter1'),
  ('WARTORTLE', 'WaterStarter2'),
  ('BLASTOISE', 'WaterStarter3'),

  ('CATERPIE', 'GrassBug1'),
  ('METAPOD', 'GrassBug1'),
  ('BUTTERFREE', 'GrassBug3'),

  ('WEEDLE', 'GrassBug1'),
  ('KAKUNA', 'GrassBug1'),
  ('BEEDRILL', 'GrassBug3'),

  ('PIDGEY', 'NormalFlying1'),
  ('PIDGEOTTO', 'NormalFlying2'),
  ('PIDGEOT', 'Overworld2'),

  ('RATTATA', 'NormalFlying1'),
  ('RATICATE', 'NormalFlying2'),

  ('SPEAROW', 'NormalFlying1'),
  ('FEAROW', 'NormalFlying2'),

  ('EKANS', 'Overworld1'),
  ('ARBOK', 'Overworld2'),

  ('PIKACHU', 'Overworld1'),
  ('RAICHU', 'Overworld2'),

  ('SANDSHREW', 'Overworld1'),
  ('SANDSLASH', 'Overworld2'),

  ('NIDORAN_F', 'Overworld1'),
  ('NIDORINA', 'Overworld2'),
  ('NIDOQUEEN', 'Overworld2'),

  ('NIDORAN_M', 'Overworld1'),
  ('NIDORINO', 'Overworld2'),
  ('NIDOKING', 'Overworld2'),

  ('CLEFAIRY', 'Spooky1'),
  ('CLEFABLE', 'Spooky2'),

  ('VULPIX', 'Overworld1'),
  ('NINETALES', 'Overworld2'),

  ('JIGGLYPUFF', 'Spooky1'),
  ('WIGGLYTUFF', 'Spooky2'),

  ('ZUBAT', 'Cave1'),
  ('GOLBAT', 'Spooky1'),

  ('ODDISH', 'GrassBug2'),
  ('GLOOM', 'GrassBug3'),
  ('VILEPLUME', 'Overworld2'),

  ('PARAS', 'Cave1'),
  ('PARASECT', 'Overworld2'),

  ('VENONAT', 'GrassBug2'),
  ('VENOMOTH', 'Overworld2'),

  ('DIGLETT', 'Cave1'),
  ('DUGTRIO', 'Cave2'),

  ('MEOWTH', 'Overworld1'),
  ('PERSIAN', 'Overworld2'),

  ('PSYDUCK', 'WaterIce1'),
  ('GOLDUCK', 'WaterIce2'),

  ('MANKEY', 'Overworld1'),
  ('PRIMEAPE', 'Overworld2'),

  ('GROWLITHE', 'Overworld1'),
  ('ARCANINE', 'Overworld2'),

  ('POLIWAG', 'WaterIce1'),
  ('POLIWHIRL', 'WaterIce2'),
  ('POLIWRATH', 'Overworld2'),

  ('ABRA', 'Overworld1'),
  ('KADABRA', 'Overworld2'),
  ('ALAKAZAM', 'NotCatchable'),

  ('MACHOP', 'Cave1'),
  ('MACHOKE', 'Cave2'),
  ('MACHAMP', 'NotCatchable'),

  ('BELLSPROUT', 'GrassBug2'),
  ('WEEPINBELL', 'GrassBug3'),
  ('VICTREEBEL', 'Overworld2'),

  ('TENTACOOL', 'WaterIce1'),
  ('TENTACRUEL', 'WaterIce2'),

  ('GEODUDE', 'Cave1'),
  ('GRAVELER', 'Cave2'),
  ('GOLEM', 'NotCatchable'),

  ('PONYTA', 'Overworld1'),
  ('RAPIDASH', 'Overworld2'),

  ('SLOWPOKE', 'WaterIce1'),
  ('SLOWBRO', 'WaterIce2'),

  ('MAGNEMITE', 'Urban1'),
  ('MAGNETON', 'Urban2'),

  ('FARFETCHD', 'NormalFlying1'),

  ('DODUO', 'NormalFlying2'),
  ('DODRIO', 'NormalFlying2'),

  ('SEEL', 'WaterIce1'),
  ('DEWGONG', 'WaterIce2'),

  ('GRIMER', 'Urban1'),
  ('MUK', 'Urban2'),

  ('SHELLDER', 'WaterIce1'),
  ('CLOYSTER', 'WaterIce2'),

  ('GASTLY', 'Spooky1'),
  ('HAUNTER', 'Spooky2'),
  ('GENGAR', 'NotCatchable'),

  ('ONIX', 'Spooky1'),

  ('DROWZEE', 'Overworld1'),
  ('HYPNO', 'Overworld2'),

  ('KRABBY', 'WaterIce1'),
  ('KINGLER', 'WaterIce2'),

  ('VOLTORB', 'Urban1'),
  ('ELECTRODE', 'Urban2'),

  ('EXEGGCUTE', 'GrassBug2'),
  ('EXEGGUTOR', 'Overworld2'),

  ('CUBONE', 'Spooky1'),
  ('MAROWAK', 'Spooky2'),

  ('HITMONLEE', 'Cave2'),
  ('HITMONCHAN', 'Cave2'),

  ('LICKITUNG', 'Overworld1'),

  ('KOFFING', 'Urban1'),
  ('WEEZING', 'Urban2'),

  ('RHYHORN', 'Overworld2'),
  ('RHYDON', 'Overworld2'),

  ('CHANSEY', 'Overworld2'),

  ('TANGELA', 'GrassBug2'),

  ('KANGASKHAN', 'Overworld2'),

  ('HORSEA', 'WaterIce1'),
  ('SEADRA', 'WaterIce2'),

  ('GOLDEEN', 'WaterIce1'),
  ('SEAKING', 'WaterIce2'),

  ('STARYU', 'WaterIce1'),
  ('STARMIE', 'WaterIce2'),

  ('MR_MIME', 'Urban1'),

  ('SCYTHER', 'GrassBug2'),

  ('JYNX', 'Urban1'),

  ('ELECTABUZZ', 'Urban1'),

  ('MAGMAR', 'Urban1'),

  ('PINSIR', 'GrassBug2'),

  ('TAUROS', 'Overworld2'),

  ('MAGIKARP', 'WaterIce1'),
  ('GYARADOS', 'NotCatchable'),

  ('LAPRAS', 'Overworld2'),

  ('DITTO', 'Urban1'),

  ('EEVEE', 'Urban1'),
  ('VAPOREON', 'WaterIce2'),
  ('JOLTEON', 'Urban2'),
  ('FLAREON', 'Urban2'),

  ('PORYGON', 'Urban1'),

  ('OMANYTE', 'WaterIce1'),
  ('OMASTAR', 'WaterIce2'),

  ('KABUTO', 'WaterIce1'),
  ('KABUTOPS', 'WaterIce2'),

  ('AERODACTYL', 'Spooky1'),

  ('SNORLAX', 'Overworld2'),

  ('ARTICUNO', 'Legendary'),
  ('ZAPDOS', 'Legendary'),
  ('MOLTRES', 'Legendary'),

  ('DRATINI', 'WaterIce1'),
  ('DRAGONAIR', 'CeruleanCave'),
  ('DRAGONITE', 'NotCatchable'),

  ('MEWTWO', 'NotInGame'),

  ('MEW', 'NotInGame'),

  ('CHIKORITA', 'GrassStarter1'),
  ('BAYLEEF', 'GrassStarter2'),
  ('MEGANIUM', 'GrassStarter3'),

  ('CYNDAQUIL', 'FireStarter1'),
  ('QUILAVA', 'FireStarter2'),
  ('TYPHLOSION', 'FireStarter3'),

  ('TOTODILE', 'WaterStarter1'),
  ('CROCONAW', 'WaterStarter2'),
  ('FERALIGATR', 'WaterStarter3'),

  ('SENTRET', 'NormalFlying1'),
  ('FURRET', 'NormalFlying2'),

  ('HOOTHOOT', 'NormalFlying1'),
  ('NOCTOWL', 'NormalFlying2'),

  ('LEDYBA', 'GrassBug1'),
  ('LEDIAN', 'GrassBug2'),

  ('SPINARAK', 'GrassBug1'),
  ('ARIADOS', 'GrassBug2'),

  ('CROBAT', 'Spooky2'),

  ('CHINCHOU', 'WaterIce1'),
  ('LANTURN', 'WaterIce2'),

  ('PICHU', 'EarlyBoost'),
  ('CLEFFA', 'Spooky1'),
  ('IGGLYBUFF', 'Spooky1'),

  ('TOGEPI', 'Urban1'),
  ('TOGETIC', 'Urban2'),

  ('NATU', 'NormalFlying1'),
  ('XATU', 'NormalFlying2'),

  ('MAREEP', 'Overworld1'),
  ('FLAAFFY', 'Overworld2'),
  ('AMPHAROS', 'Overworld2'),

  ('BELLOSSOM', 'Overworld2'),

  ('MARILL', 'Overworld1'),
  ('AZUMARILL', 'Overworld2'),

  ('SUDOWOODO', 'Overworld1'),

  ('POLITOED', 'Overworld2'),

  ('HOPPIP', 'NormalFlying1'),
  ('SKIPLOOM', 'GrassBug2'),
  ('JUMPLUFF', 'GrassBug3'),

  ('AIPOM', 'NormalFlying1'),

  ('SUNKERN', 'GrassBug1'),
  ('SUNFLORA', 'GrassBug2'),

  ('YANMA', 'GrassBug1'),

  ('WOOPER', 'WaterIce1'),
  ('QUAGSIRE', 'WaterIce2'),

  ('ESPEON', 'Spooky2'),
  ('UMBREON', 'Cave2'),

  ('MURKROW', 'Spooky1'),

  ('SLOWKING', 'Overworld2'),

  ('MISDREAVUS', 'Spooky1'),

  ('UNOWN', 'NotInGame'),

  ('WOBBUFFET', 'NotInGame'),

  ('GIRAFARIG', 'Overworld1'),

  ('PINECO', 'GrassBug1'),
  ('FORRETRESS', 'GrassBug3'),

  ('DUNSPARCE', 'Cave1'),

  ('GLIGAR', 'Cave1'),

  ('STEELIX', 'Spooky2'),

  ('SNUBBULL', 'NormalFlying1'),
  ('GRANBULL', 'NormalFlying2'),

  ('QWILFISH', 'WaterIce1'),

  ('SCIZOR', 'NotCatchable'),

  ('SHUCKLE', 'Cave1'),

  ('HERACROSS', 'GrassBug2'),

  ('SNEASEL', 'Cave1'),

  ('TEDDIURSA', 'NormalFlying1'),
  ('URSARING', 'NormalFlying2'),

  ('SLUGMA', 'Urban1'),
  ('MAGCARGO', 'Urban2'),

  ('SWINUB', 'Cave1'),
  ('PILOSWINE', 'Cave2'),

  ('CORSOLA', 'WaterIce1'),

  ('REMORAID', 'WaterIce1'),
  ('OCTILLERY', 'WaterIce2'),

  ('DELIBIRD', 'NormalFlying1'),

  ('MANTINE', 'WaterIce1'),

  ('SKARMORY', 'NormalFlying2'),

  ('HOUNDOUR', 'Overworld1'),
  ('HOUNDOOM', 'Overworld2'),

  ('KINGDRA', 'NotCatchable'),

  ('PHANPY', 'Overworld1'),
  ('DONPHAN', 'Overworld2'),

  ('PORYGON2', 'Urban2'),

  ('STANTLER', 'NormalFlying1'),
  ('SMEARGLE', 'NotInGame'),

  ('TYROGUE', 'Cave1'),

  ('HITMONTOP', 'Cave2'),

  ('SMOOCHUM', 'EarlyBoost'),

  ('ELEKID', 'EarlyBoost'),

  ('MAGBY', 'EarlyBoost'),

  ('MILTANK', 'Overworld1'),

  ('BLISSEY', 'NotCatchable'),

  ('RAIKOU', 'NotInGame'),
  ('ENTEI', 'NotInGame'),
  ('SUICUNE', 'NotInGame'),

  ('LARVITAR', 'Spooky1'),
  ('PUPITAR', 'CeruleanCave'),
  ('TYRANITAR', 'NotCatchable'),

  ('LUGIA', 'NotInGame'),
  ('HO_OH', 'NotInGame'),

  ('CELEBI', 'NotInGame'),

  ('TREECKO', 'GrassStarter1'),
  ('GROVYLE', 'GrassStarter2'),
  ('SCEPTILE', 'GrassStarter3'),

  ('TORCHIC', 'FireStarter1'),
  ('COMBUSKEN', 'FireStarter2'),
  ('BLAZIKEN', 'FireStarter3'),

  ('MUDKIP', 'WaterStarter1'),
  ('MARSHTOMP', 'WaterStarter2'),
  ('SWAMPERT', 'WaterStarter3'),

  ('POOCHYENA', 'NormalFlying1'),
  ('MIGHTYENA', 'NormalFlying2'),

  ('ZIGZAGOON', 'NormalFlying1'),
  ('LINOONE', 'NormalFlying2'),

  ('WURMPLE', 'GrassBug1'),
  ('SILCOON', 'GrassBug1'),
  ('BEAUTIFLY', 'GrassBug3'),
  ('CASCOON', 'Cave1'),
  ('DUSTOX', 'GrassBug3'),

  ('LOTAD', 'GrassBug2'),
  ('LOMBRE', 'GrassBug3'),
  ('LUDICOLO', 'Overworld2'),

  ('SEEDOT', 'GrassBug2'),
  ('NUZLEAF', 'GrassBug3'),
  ('SHIFTRY', 'Overworld2'),

  ('TAILLOW', 'NormalFlying1'),
  ('SWELLOW', 'NormalFlying2'),

  ('WINGULL', 'WaterIce1'),
  ('PELIPPER', 'WaterIce2'),

  ('RALTS', 'Overworld1'),
  ('KIRLIA', 'Overworld2'),
  ('GARDEVOIR', 'NotCatchable'),

  ('SURSKIT', 'WaterIce1'),
  ('MASQUERAIN', 'WaterIce2'),

  ('SHROOMISH', 'GrassBug2'),
  ('BRELOOM', 'NotCatchable'),

  ('SLAKOTH', 'Overworld1'),
  ('VIGOROTH', 'Overworld2'),
  ('SLAKING', 'NotCatchable'),

  ('NINCADA', 'GrassBug1'),
  ('NINJASK', 'GrassBug3'),
  ('SHEDINJA', 'NotInGame'),

  ('WHISMUR', 'Cave1'),
  ('LOUDRED', 'Cave2'),
  ('EXPLOUD', 'NotCatchable'),

  ('MAKUHITA', 'Cave1'),
  ('HARIYAMA', 'Cave2'),

  ('AZURILL', 'EarlyBoost'),

  ('NOSEPASS', 'Cave1'),

  ('SKITTY', 'Overworld1'),
  ('DELCATTY', 'Overworld2'),

  ('SABLEYE', 'Spooky1'),

  ('MAWILE', 'Spooky1'),

  ('ARON', 'Cave1'),
  ('LAIRON', 'Cave2'),
  ('AGGRON', 'NotCatchable'),

  ('MEDITITE', 'Cave1'),
  ('MEDICHAM', 'Cave2'),

  ('ELECTRIKE', 'Overworld1'),
  ('MANECTRIC', 'Overworld2'),

  ('PLUSLE', 'Urban1'),

  ('MINUN', 'NotInGame'),

  ('VOLBEAT', 'GrassBug1'),

  ('ILLUMISE', 'GrassBug2'),

  ('ROSELIA', 'GrassBug2'),

  ('GULPIN', 'Overworld1'),
  ('SWALOT', 'Overworld2'),

  ('CARVANHA', 'WaterIce1'),
  ('SHARPEDO', 'WaterIce2'),

  ('WAILMER', 'WaterIce1'),
  ('WAILORD', 'WaterIce2'),

  ('NUMEL', 'Overworld1'),
  ('CAMERUPT', 'Overworld2'),

  ('TORKOAL', 'Overworld2'),

  ('SPOINK', 'Overworld1'),
  ('GRUMPIG', 'Overworld2'),

  ('SPINDA', 'NormalFlying1'),

  ('TRAPINCH', 'Overworld1'),
  ('VIBRAVA', 'CeruleanCave'),
  ('FLYGON', 'NotCatchable'),

  ('CACNEA', 'GrassBug2'),
  ('CACTURNE', 'GrassBug3'),

  ('SWABLU', 'NormalFlying1'),
  ('ALTARIA', 'NormalFlying2'),

  ('ZANGOOSE', 'Overworld1'),

  ('SEVIPER', 'Overworld1'),

  ('LUNATONE', 'Spooky1'),

  ('SOLROCK', 'Cave1'),

  ('BARBOACH', 'WaterIce1'),
  ('WHISCASH', 'WaterIce2'),

  ('CORPHISH', 'WaterIce1'),
  ('CRAWDAUNT', 'WaterIce2'),

  ('BALTOY', 'Spooky1'),
  ('CLAYDOL', 'Spooky2'),

  ('LILEEP', 'GrassBug2'),
  ('CRADILY', 'GrassBug3'),

  ('ANORITH', 'Cave1'),
  ('ARMALDO', 'Cave2'),

  ('FEEBAS', 'WaterIce1'),
  ('MILOTIC', 'NotCatchable'),

  ('CASTFORM', 'NotInGame'),

  ('KECLEON', 'Overworld1'),

  ('SHUPPET', 'Spooky1'),
  ('BANETTE', 'Spooky2'),

  ('DUSKULL', 'Spooky1'),
  ('DUSCLOPS', 'Spooky2'),

  ('TROPIUS', 'Overworld1'),

  ('CHIMECHO', 'Overworld1'),

  ('ABSOL', 'Overworld1'),

  ('WYNAUT', 'NotInGame'),

  ('SNORUNT', 'Cave1'),
  ('GLALIE', 'Cave2'),

  ('SPHEAL', 'WaterIce1'),
  ('SEALEO', 'WaterIce2'),
  ('WALREIN', 'Overworld2'),

  ('CLAMPERL', 'WaterIce1'),
  ('HUNTAIL', 'WaterIce2'),
  ('GOREBYSS', 'WaterIce2'),

  ('RELICANTH', 'WaterIce1'),

  ('LUVDISC', 'NotInGame'),

  ('BAGON', 'GrassBug2'),
  ('SHELGON', 'CeruleanCave'),
  ('SALAMENCE', 'NotCatchable'),

  ('BELDUM', 'Urban1'),
  ('METANG', 'CeruleanCave'),
  ('METAGROSS', 'NotCatchable'),

  ('REGIROCK', 'NotInGame'),
  ('REGICE', 'NotInGame'),
  ('REGISTEEL', 'NotInGame'),

  ('LATIAS', 'NotInGame'),
  ('LATIOS', 'NotInGame'),

  ('KYOGRE', 'NotInGame'),
  ('GROUDON', 'NotInGame'),
  ('DUSKNOIR', 'NotInGame'),

  ('JIRACHI', 'NotInGame'),

  ('DEOXYS', 'NotInGame'),

  ('TURTWIG', 'NULL'),
  ('GROTLE', 'NULL'),
  ('TORTERRA', 'NULL'),
  ('CHIMCHAR', 'NULL'),
  ('MONFERNO', 'NULL'),
  ('INFERNAPE', 'NULL'),
  ('PIPLUP', 'NULL'),
  ('PRINPLUP', 'NULL'),
  ('EMPOLEON', 'NULL'),
  ('STARLY', 'NULL'),
  ('STARAVIA', 'NULL'),
  ('STARAPTOR', 'NULL'),
  ('BIDOOF', 'NULL'),
  ('BIBAREL', 'NULL'),
  ('KRICKETOT', 'NULL'),
  ('KRICKETUNE', 'NULL'),
  ('SHINX', 'NULL'),
  ('LUXIO', 'NULL'),
  ('LUXRAY', 'NULL'),
  ('BUDEW', 'EarlyBoost'),
  ('ROSERADE', 'NotCatchable'),
  ('CRANIDOS', 'NULL'),
  ('RAMPARDOS', 'NULL'),
  ('SHIELDON', 'NULL'),
  ('BASTIODON', 'NULL'),
  ('BURMY', 'NULL'),
  ('WORMADAM', 'NULL'),
  ('MOTHIM', 'NULL'),
  ('COMBEE', 'NULL'),
  ('VESPIQUEN', 'NULL'),
  ('PACHIRISU', 'NULL'),
  ('BUIZEL', 'NULL'),
  ('FLOATZEL', 'NULL'),
  ('CHERUBI', 'NULL'),
  ('CHERRIM', 'NULL'),
  ('SHELLOS', 'NULL'),
  ('GASTRODON', 'NULL'),
  ('AMBIPOM', 'NormalFlying2'),
  ('DRIFLOON', 'NULL'),
  ('DRIFBLIM', 'NULL'),
  ('BUNEARY', 'NULL'),
  ('LOPUNNY', 'NULL'),
  ('MISMAGIUS', 'Spooky2'),
  ('HONCHKROW', 'Spooky2'),
  ('GLAMEOW', 'NULL'),
  ('PURUGLY', 'NULL'),
  ('CHINGLING', 'NotInGame'),
  ('STUNKY', 'NULL'),
  ('SKUNTANK', 'NULL'),
  ('BRONZOR', 'NULL'),
  ('BRONZONG', 'NULL'),
  ('BONSLY', 'NotInGame'),
  ('MIME_JR', 'EarlyBoost'),
  ('HAPPINY', 'Overworld1'),
  ('CHATOT', 'NULL'),
  ('SPIRITOMB', 'NULL'),
  ('GIBLE', 'NULL'),
  ('GABITE', 'NULL'),
  ('GARCHOMP', 'NULL'),
  ('MUNCHLAX', 'Overworld1'),
  ('RIOLU', 'NULL'),
  ('LUCARIO', 'NULL'),
  ('HIPPOPOTAS', 'NULL'),
  ('HIPPOWDON', 'NULL'),
  ('SKORUPI', 'NULL'),
  ('DRAPION', 'NULL'),
  ('CROAGUNK', 'NULL'),
  ('TOXICROAK', 'NULL'),
  ('CARNIVINE', 'NULL'),
  ('FINNEON', 'NULL'),
  ('LUMINEON', 'NULL'),
  ('MANTYKE', 'NotInGame'),
  ('SNOVER', 'NULL'),
  ('ABOMASNOW', 'NULL'),
  ('WEAVILE', 'NotCatchable'),
  ('MAGNEZONE', 'NotCatchable'),
  ('LICKILICKY', 'Overworld2'),
  ('RHYPERIOR', 'NotCatchable'),
  ('TANGROWTH', 'GrassBug3'),
  ('ELECTIVIRE', 'Urban2'),
  ('MAGMORTAR', 'Urban2'),
  ('TOGEKISS', 'NotCatchable'),
  ('YANMEGA', 'GrassBug3'),
  ('LEAFEON', 'GrassBug3'),
  ('GLACEON', 'WaterIce2'),
  ('GLISCOR', 'NotCatchable'),
  ('MAMOSWINE', 'NotCatchable'),
  ('PORYGON_Z', 'NotCatchable'),
  ('GALLADE', 'NotCatchable'),
  ('PROBOPASS', 'Cave2'),
  ('DUSKNOIR', 'NotCatchable'),
  ('FROSLASS', 'Spooky2'),
  ('ROTOM', 'NULL'),
  ('UXIE', 'NULL'),
  ('MESPRIT', 'NULL'),
  ('AZELF', 'NULL'),
  ('DIALGA', 'NULL'),
  ('PALKIA', 'NULL'),
  ('HEATRAN', 'NULL'),
  ('REGIGIGAS', 'NULL'),
  ('GIRATINA', 'NULL'),
  ('CRESSELIA', 'NULL'),
  ('PHIONE', 'NULL'),
  ('MANAPHY', 'NULL'),
  ('DARKRAI', 'NULL'),
  ('SHAYMIN', 'NULL'),
  ('ARCEUS', 'NULL'),

  ('OLD_UNOWN_B', 'NULL'),
  ('OLD_UNOWN_C', 'NULL'),
  ('OLD_UNOWN_D', 'NULL'),
  ('OLD_UNOWN_E', 'NULL'),
  ('OLD_UNOWN_F', 'NULL'),
  ('OLD_UNOWN_G', 'NULL'),
  ('OLD_UNOWN_H', 'NULL'),
  ('OLD_UNOWN_I', 'NULL'),
  ('OLD_UNOWN_J', 'NULL'),
  ('OLD_UNOWN_K', 'NULL'),
  ('OLD_UNOWN_L', 'NULL'),
  ('OLD_UNOWN_M', 'NULL'),
  ('OLD_UNOWN_N', 'NULL'),
  ('OLD_UNOWN_O', 'NULL'),
  ('OLD_UNOWN_P', 'NULL'),
  ('OLD_UNOWN_Q', 'NULL'),
  ('OLD_UNOWN_R', 'NULL'),
  ('OLD_UNOWN_S', 'NULL'),
  ('OLD_UNOWN_T', 'NULL'),
  ('OLD_UNOWN_U', 'NULL'),
  ('OLD_UNOWN_V', 'NULL'),
  ('OLD_UNOWN_W', 'NULL'),
  ('OLD_UNOWN_X', 'NULL'),
  ('OLD_UNOWN_Y', 'NULL'),
  ('OLD_UNOWN_Z', 'NULL'),

  ('EGG', 'NULL'),
  ('UNOWN_B', 'NULL'),
  ('UNOWN_C', 'NULL'),
  ('UNOWN_D', 'NULL'),
  ('UNOWN_E', 'NULL'),
  ('UNOWN_F', 'NULL'),
  ('UNOWN_G', 'NULL'),
  ('UNOWN_H', 'NULL'),
  ('UNOWN_I', 'NULL'),
  ('UNOWN_J', 'NULL'),
  ('UNOWN_K', 'NULL'),
  ('UNOWN_L', 'NULL'),
  ('UNOWN_M', 'NULL'),
  ('UNOWN_N', 'NULL'),
  ('UNOWN_O', 'NULL'),
  ('UNOWN_P', 'NULL'),
  ('UNOWN_Q', 'NULL'),
  ('UNOWN_R', 'NULL'),
  ('UNOWN_S', 'NULL'),
  ('UNOWN_T', 'NULL'),
  ('UNOWN_U', 'NULL'),
  ('UNOWN_V', 'NULL'),
  ('UNOWN_W', 'NULL'),
  ('UNOWN_X', 'NULL'),
  ('UNOWN_Y', 'NULL'),
  ('UNOWN_Z', 'NULL'),
  ('UNOWN_EMARK', 'NULL'),
  ('UNOWN_QMARK', 'NULL'),
]

c_top = '''
#ifndef GUARD_AUTOGENERATED_POKEMON_GROUPS_H
#define GUARD_AUTOGENERATED_POKEMON_GROUPS_H

// +------------------------------------------------------+
// | !!! AUTOGENERATED BY generate_docs_and_groups.py !!! |
// +------------------------------------------------------+

#include "data.h"
#include "global.h"

'''

c_bottom = 'const u16* const gMonGroups[] =\n{\n  [SPECIES_NONE] = NULL,\n'

groups = {
  'EarlyBoost': [],
  'NormalFlying1': [],
  'NormalFlying2': [],
  'Cave1': [],
  'Cave2': [],
  'GrassBug1': [],
  'GrassBug2': [],
  'GrassBug3': [],
  'Spooky1': [],
  'Spooky2': [],
  'Urban1': [],
  'Urban2': [],
  'WaterIce1': [],
  'WaterIce2': [],
  'Overworld1': [],
  'Overworld2': [],
  'CeruleanCave': [],
  'NotCatchable': [],
  'Legendary': [],
  'NotInGame': [],
}

def rel_nat_dex_pos(x):
  # Machop, Gastly, Togepi, Togetic, Trapinch, and Happiny
  # are much better than their dex numbers suggest.
  if x in set([66, 92, 175, 176, 328, 440]):
    return 0.9
  if x <= 151:
    return x / 151
  if x <= 251:
    # Johto dex is small and has good pokemon, so scale them.
    return (x - 151) / (251 - 151) * 0.95 + 0.025
  if x <= 386:
    return (x - 251) / (386 - 251)
  return (x - 386) / (494 - 386)

sorted_dex_nums = sorted([x for x in range(1, 494)], key=rel_nat_dex_pos)
for pokedex_num in sorted_dex_nums:
  (poke_name, group_name) = pokes[pokedex_num]
  if group_name == 'NULL':
    continue
  if group_name not in groups:
    groups[group_name] = []
  groups[group_name].append((pokedex_num, poke_name))
  if group_name != 'NotInGame':
    c_bottom += '  [SPECIES_' + poke_name + '] = gGroup_' + group_name + ',\n'
c_bottom += '};\n'

for starter_group in ['GrassStarter1', 'FireStarter1', 'WaterStarter1']:
  groups['EarlyBoost'].extend(groups[starter_group])

md = ''

for group_name, pokes_with_id in groups.items():
  if group_name == 'NULL':
    continue

  not_starter_group = 'Starter' not in group_name

  if not_starter_group:
    md += '| ' + group_name + ' |\n| --- |\n|'
  if group_name != "NotInGame":
    c = 'const u16 gGroup_' + group_name + '[] =\n{\n  /*SIZE=*/' + str(len(pokes_with_id)) + ',\n'
  else:
    c = ''

  for (poke_id, poke_name) in pokes_with_id:
    if not_starter_group:
      dex_num = str(poke_id).rjust(3, '0')
      image_url = 'https://www.serebii.net/pokedex-swsh/icon/' + dex_num + '.png'
      link_url = 'https://www.serebii.net/pokedex-dp/' + dex_num + '.shtml'
      md += '[![](' + image_url + " '" + poke_name + "')](" + link_url + ')'
    if group_name != "NotInGame":
      c += '  SPECIES_' + poke_name + ',\n'

  if not_starter_group:
    md += '|\n\n'
  if group_name != "NotInGame":
    c_top += c + '};\n\n'

with open('README.md', 'w') as md_file:
  md_file.write('''# Pokémon Challenge

https://github.com/alecwshearer/poke-challenge is a fork of https://github.com/pret/pokefirered that is meant to be played by multiple players in a timed challenge. The game doesn't support link battles -- players can battle using [Pokémon Showdown](https://pokemonshowdown.com/).

Major changes:
 - **Deterministic game seed:** Wild Pokémon, trainer Pokémon, and overworld items are randomized based on the Rival name specified at the beginning of the game. All non-key overworld items contain TMs. Some items may be randomly placed on water or in unreachable areas.
 - **Time limit:** After 5 hours pass, the player is locked in the Celadon Department Store. The game clock doesn't decrease while the START menu is active, including when the player is using the Pokémon summary screen, bag, etc. outside of battle.
 - **Level band:** Pokémon stop gaining experience if they become too overleveled compared to the rest of the team. Rare candies also stop working.
 - **Level scaling:** Wild and trainer Pokémon levels increase based on the player's party Pokémon levels and badge count.
 - **Gen 4 Pokemon, Moves, TMs, Abilities, & Items:** Most Gen 4 Pokémon in Gen 1-3 families (e.g. Munchlax, Weavile) are added, with Gen IV HG/SS learnsets and abilities. The Department Store sells Gen 4 battle items, Nature Mints, and Ability Patches. Many Gen IV moves and abilities aren't implemented properly, and instead have placeholder effects. The full Pokémon list at the bottom of this page.
 - **New TMs and learnsets:** 64 TMs are added to the game, bringing the total to 156. Fully evolved Pokémon learn non-TM pre-evolution and egg moves at level 1. TMs can teach moves that were previously only learnable via breeding or move tutors. I.e. if a move is on Smogon it can be learned in this game. A free Move Relearner are added to the Department Store.

Helpful code links:
 - TM list: https://github.com/alecwshearer/poke-challenge/blob/master/all_tms.txt
 - Pokémon level-up learnsets (including level 1): https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/level_up_learnsets.h
 - Pokémon TM01-TM50 and HM learnsets: https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/tmhm_learnsets.h
 - Pokémon TM51-TM92 learnsets: https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/gen4_tmhm_learnsets.h
 - Pokémon TM93-TM156 learnsets: https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/new_tmhm_learnsets.h
 - Pokémon evolution conditions: https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/evolution.h
 - Celadon City 5th floor items: https://github.com/alecwshearer/poke-challenge/blob/master/data/maps/CeladonCity_DepartmentStore_5F/scripts.inc
 - Item prices (CTRL+F for "price"): https://github.com/alecwshearer/poke-challenge/blob/master/src/data/items.json

Other changes:
 - Faster movement, animations, and text. Hold B to use normal walking speed.
 - Start the game with balls, healing items, the Old Rod, 6 Exp Shares, and more.
 - L button maps to A button. In battles, L button auto-fires A and holding R automatically runs away.
 - Gain experience for catching Pokémon.
 - Oak's aides give large sums of money for completing the Pokédex. You can find them in the Department Store and their original locations. The rewards are as follows:
   - 500 for 1 unique species.
   - 5k for 20 unique species.
   - 10k for 40 unique species.
   - 20k for 60 unique species.
   - 40k for 80 unique species.
   - 80k for 100 unique species.
 - Starter Pokémon are randomized based on the game seed. There is still one grass, water, and fire starter, and they will be chosen from the gen 1-3 starters.
 - Move tutors give the player a random TM instead. Purchasable, winnable, and gift TMs are randomized.
 - Gym leaders give the player a Rare Candy in addition to a TM upon earning a badge.
 - Legendary birds give the player a Rare Candy upon defeat.
 - Elite Four members give the player a Rare Candy and Nature Mint upon defeat (first time only).
 - The Champion gives the player a Rare Candy, Nature Mint, and Ability Patch upon defeat (every time).
 - The Karate Master gives the player a MACHO BRACE.
 - Overworld Pokémon (e.g. Snorlax, Articuno) can't be caught.
 - Physical/special split.
 - Pokémon that evolve above level 45 now evolve at level 45 instead.
 - Gift Pokémon are replaced with Spinda.
 - Items aren't sellable.
 - HMs are deletable without the Move Deleter.
 - Flash is no longer required in Rock Tunnel.
 - Old Amber is removed from the game.
 - Trade and happiness evolutions have been replaced with a new "Trade+ Stone", or Sun Stone & Moon Stone in cases where one Pokémon can evolve into multiple others (e.g. Eevee into Espeon or Umbreon). See full list [here](https://github.com/alecwshearer/poke-challenge/blob/master/src/data/pokemon/evolution.h).
 - Tyrogue can evolve using Sun Stone (Hitmonchan), Moon Stone (Hitmonlee), and Trade+ Stone (Hitmontop) in addition to his normal level 20 evolution. You can avoid evolving by pressing B if you want to wait to use a stone.
 - Pokémon that evolve by knowing a move (e.g. Ancient Power) instead evovle at the first level that they can know the move.
 - Player finds the Good Rod where the Old Rod used to be, and Super Rod where Good Rod used to be. The Super Rod can also still be found at its original location.
 - The PC is accessible from the START menu. Pokémon no longer heal when sent to the PC.
 - Start with a coin case containing 100 coins. Can no longer buy coins at the Game Corner. Earn 50 pity coins when you run out of coins at the slot machines.
 - The following prizes can be won at the Game Corner:
    - 100 Coins each: TMs for weather moves and Trick Room.
    - 150 Coins each: 6 random TMs, chosen based on the game seed.
    - 150 Coins: Level 1 Pikachu that knows Surf and Fly.
    - 150 Coins: Replacement Smeargle.
      - On Pokémon Showdown you can replace this with a Smeargle that knows any move that you have a TM for (exhausting the TM), and the EVs & IVs of any Pokémon that's not a part of your final team.
    - 150 Coins: Level 50 Ditto (can only be bought once -- subsequent ones are at level 2).
    - 300 Coins: Level 20 Lapras.
    - 500 Coins: Level 20 Eevee.
 - Players can see their party's hidden power type and power in the "POKéMON INFO" summary screen.
 - Players can see their party's EVs and IVs by holding L and R respectively in the "POKéMON SKILLS" summary screen.
 - Repel works on all wild Pokémon, regardless of level.
 - Player gets 10x the number of steps in the Safari Zone.
 - Shiny Pokémon odds are increased 10x.
 - Party menu shortcut for giving/taking Exp Shares.
 - The Arena Trap ability has been removed from the game.
 - Safari Balls are 53% more effective, which makes them 15% more effective than Ultra Balls.
 - Pewter, Cerulean, and Vermillion Marts sell Revives.
 - Celadon Mart sells Ultra Balls.
 - All Pokémon that aren't normally catchable in the Safari Zone have a Safari Zone [flee rate](https://bulbapedia.bulbagarden.net/wiki/Kanto_Safari_Zone) of 75 (base 25% chance of fleeing).
 - Some early events are skipped; e.g. the Old Man.
 - Slightly modified wild encounters:
   - Dragonair -> Seadra
   - Wobbuffet -> Dragonair
   - Unown -> Zubat
   - Smeargle -> Zubat
 - Surge's gym "puzzle" is simplified. Player always find the second switch on their first try.
 - Fishing rod hit rate is increased from 50% to 75%.
 - Misc. bugfixes included in the https://github.com/pret/pokefirered `firered_rev1_modern` build.

## Level band / level cap

**TL;DR: Your Pokémon will stop gaining experience if they become too high a level compared to the rest of your team. The game will warn you when this is close to happening. The number of Pokémon considered depends on the number of badges you have.**

A 7 level band is in place. A portion of the player's team must be within 7 levels, inclusive, of each other;
e.g. a range of 30-37 is valid but 30-38 isn’t. The number of Pokémon that must be within the band is equal
to the number of badges the player has plus 1, _with a maximum cutoff of 5_. For example, the player has 3 badges,
they must have 4 Pokémon within 7 levels (inclusive) of each other. The fact that the 6th Pokémon isn't taken into
account means that 1 low level Pokémon can be safely carried around for HM use, Pickup, etc.

Rare candies do not work on Pokémon that are at the level cap.

If a Pokémon reaches the top of the band (also called the _level cap_), it will not be able to progress to the next
level, and won't be able to gain EXP once its EXP bar is filled. Other party Pokémon holding an EXP share will still
gain EXP, but any missed EXP that the Pokémon at the cap would have gained won’t be distributed to the other party
Pokémon. Note that, as in base FireRed, Pokémon that don't gain EXP also don't gain EVs.

The game will issue warnings when a Pokémon is near the current level cap, or the cap at the next badge. The latter
warning can be disabled in the OPTION menu, but this is not advised.

## Level scaling

### Wild encounters

**TL;DR: Wild Pokémon levels approach your party's average level as you gain badges. Your 1st and 6th highest level Pokémon are excluded from the calculation. Your party size must increase as you earn badges to take advantage of this.**

Wild Pokémon levels are scaled based on party Pokémon levels and the level that the wild Pokémon is supposed to be at. This is done by:
- Summing the levels of your 2nd through 5th highest Pokémon, for as many badges as you have.
  - I.e., your 1st and 6th higest Pokémon are ignored and the others are cycled through from higeest to lowest.
- Adding the level the wild Pokémon is supposed to be at.
- Dividing by the number of badges you have plus 1.

If you have fewer Pokémon in your party than the number of Pokémon required by the formula, empty party slots will be treated as level 2 Pokémon.

#### Example: less than 4 badges

Input:
 - **Number of badges:** 2
 - **Party Pokémon levels:** 20, 17, 16
 - **Level the wild Pokémon is supposed to be at:** 10

Output:
 - **Scaled level:** ⌊(`weighted_team_sum` + `original_wild_level`) / (`badge_count` + 1)⌋ = ⌊((17 + 16) + 10) / 3⌋ = ⌊43 / 3⌋ = 14

#### Example: more than 4 badges

Input:
 - **Number of badges:** 5
 - **Party Pokémon levels:** 28, 24, 22, 21, 20, 12
 - **Level the wild Pokémon is supposed to be at:** 14

Output:
 - **Scaled level:** (`weighted_team_sum` + `original_wild_level`) / (`badge_count` + 1)⌋ = ⌊((24 + 22 + 21 + 20 + 24) + 14) / 6⌋ = ⌊125 / 6⌋ = 20

#### Example: not enough Pokémon in party

Input:
 - **Number of badges:** 2
 - **Party Pokémon levels:** 20, 8
 - **Level the wild Pokémon is supposed to be at:** 6

Output:
 - **Scaled level:** ⌊(`weighted_team_sum` + `original_wild_level`) / (`badge_count` + 1)⌋ = ⌊((8 + **2**) + 6) / 3⌋ = ⌊16 / 3⌋ = 5

#### Exception for high level Pokémon

To disincentivize players from rushing to later routes to catch all of their Pokémon, wild Pokémon that
are supposed to be at level greater than or equal to the player's highest Pokémon will have their level
multiplied by 0.67 before it is plugged into the scaling formula.

### Trainer battles

**TL;DR: Trainer Pokémon levels increase by 0.5 on average for each badge you have.**

Trainer Pokémon levels are increased based on the number of badges the player has. For each odd numbered badge,
odd numbered trainer Pokémon levels are increased by 1. For each even numbered badge, even numbered trainer
Pokémon levels are increased by 1.

#### Example

| Player badge count  | Trainer party levels     |
| ------------------- | ------------------------ |
| 0 (vanilla FireRed) |   10,   10,   11,   11   |
| 1                   |   10, **11**, 11, **12** |
| 2                   | **11**, 11, **12**, 12   |
| 3                   |   11, **12**, 12, **13** |
| 4                   | **12**, 12, **13**, 13   |
| 5                   |   12, **13**, 13, **14** |
| 6                   | **13**, 13, **14**, 14   |
| 7                   |   13, **14**, 14, **15** |
| 8                   | **14**, 14, **15**, 15   |

## Pokémon randomization

Each Pokémon belongs to a group. Based on the Rival name specified at the
beginning of the game, Pokémon encountered in the normal FireRed game are
replaced with Pokémon from their group, as described below.

### Wild encounters

For every "map set" (e.g. Route 1, Mt. Moon) in the game:
  - All fishing Pokémon are deterministically replaced with 1 species from their
  group, regardless of encounter rate.
  - Non-fishing Pokémon with an encounter rate less than or equal to 20% are
  deterministically replaced with 1 species from their group.
  - Non-fishing Pokémon with an encounter rate greater than 20% are deterministically
  replaced with 2 _distinct_ species from their group. There is a ~66% and ~33% chance of
  encountering the 2 replacements, respectively. The Pokémon that comes first the group will
  be the more likely encounter, and one that comes later will be the less likely one.

Pokémon that are catchable via multiple methods (e.g. fishing and walking) in the same route
are replaced with the same Pokémon for each method.

#### Map sets

A "map set" is a collection of game locations that use the same Pokémon
replacement mappings. Note that this is a term specific to this ROM-hack, and is
different than the "map group" concept in the FR/LG source code.

The list of map sets is below. Any map that isn't in this list is in its own map set:

##### Dungeons:
- Mt. Moon 1F, B1F, B2F
- Rock Tunnel 1F, B1F
- Diglett's Cave North Entrace, South Entrance, B1F
- Pokémon Tower 4F, 5F, 6F
- Pokémon Tower 7F, 8F
- Pokémon Mansion 1F, B1F
- Pokémon Mansion 2F, 3F
- Seafoam Islands 1F, B1F, B2F
- Seafoam Islands B3F, B4F
- Victory Road 1F, 2F, 3F
- Mt. Ember Summit Path 1F, 2F, 3F

##### Water routes:
- Pallet Town, Route 20, Cinnabar Island
- Vermilion City, Route 11
- Route 12, Route 13
- Route 19, Route 20

#### Early boost

Additionally, each non-water game map (not map set) is deterministically assigned a
single Pokémon from the `EarlyBoost` group. The chance of finding one of these
Pokémon starts at 4%, and decreases by 0.5% for each badge you have.

#### Example

![Mt. Moon map set example](map_set_example.png "Mt. Moon Map Set")

In Mt. Moon, each species is replaced with 1 or 2 species from their group, depending
on the catch rate. We see that Paras' second replacement is only encounterable on
floor B1F, because that's the only floor where Paras has a catch rate >20% in the
original game. The EarlyBoost Pokémon will have a rate of 0-4%, depending on the number
of badges the player has (other rates will be adjusted acordingly).

### Trainer battles

Trainer Pokémon are deterministically replaced with a single Pokémon from their group.

### Group list

Pokémon that come first in these group are more likely to be the more common substitution
in situations where a Pokémon maps to 2 species (i.e. for non-fishing Pokémon with a >20%
encounter rate).

''' + md)

with open('include/autogenerated_pokemon_groups.h', 'w') as c_file:
  c_file.write(c_top + c_bottom + '\n#endif\n')

