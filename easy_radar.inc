#if defined (easy_radar__included)
	#endinput
#endif
#define easy_radar__included

#if !defined (MAX_RADARS)
	#define MAX_RADARS		150
#endif

#if !defined (RADARS_3DTEXT_LABEL)
	static RADARS_3DTEXT_LABEL[] = "{ff9945}Камера на %i км/ч\nПоставил: {c2c2c2}%s (ID: %i)";
#endif

#if !defined (RADARS_STREAM_DISTANCE)
	#define RADARS_STREAM_DISTANCE 150.0
#endif

#if !defined (RADARS_WARNING_TEXT)
	static RADARS_WARNING_TEXT[] = "На данном участке дороге ограничение скорости, будь внимателен и снизь скорость!";
#endif

/*
Система штрафов работает так, если человек превысил скорость условно на 10 км/ч, то сумма будет умножаться на установленную сумму за нарушение.
Сейчас это 2000 вирт
*/

#if !defined (RADARS_TICKET_TEXT)
	static RADARS_TICKET_TEXT[] = "{ff9945}SMS: {ffffff} Ваш автомобиль нарушил скоростной режим. Штраф в размере {ff9945}$%i{ffffff} будет снят с вашего банковского счёта.";
#endif

#if !defined (RADARS_INFO_TEXT)
	static RADARS_INFO_TEXT[] = "{47bcff}[Speed Cam]{ffffff} Камера в %s засекла нарушение. Автомобиль: %s. Водитель: %s";
#endif

#if !defined (RADARS_DELETE_TEXT)
	static RADARS_DELETE_TEXT[] = "{47bcff}[Speed Cam]{ffffff} %s удалил камеру в местности %s.";
#endif

#if !defined (RADARS_CREATE_TEXT)
	static RADARS_CREATE_TEXT[] = "{47bcff}[Speed Cam]{ffffff} %s создал камеру на %i км/ч в местности %s.";
#endif

#if !defined (MAX_PLACE_NAME)
	#define MAX_PLACE_NAME 24
#endif

#if !defined (PAWNCMD_INC_) && !defined (DC_CMD)
	#define RADARS_TYPE_BASIC
#else
	#define RADARS_TYPE_MAIN
#endif

#if !defined (TICKETS_SHOW_TEAM)
	#error Please, define TICKETS_SHOW_TEAM
#endif

#if !defined (RADAR_OBJECT)
	#define RADAR_OBJECT		(18880)
#endif

static Easy_CarNames[][] =
{
	"Landstalker", "Bravura", "Buffalo", "Linerunner", "Pereniel", "Sentinel", "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus", "Voodoo", "Pony",
	"Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", "Esperanto", "Taxi", "Washington", "Bobcat", "Mr Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer",
	"Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie", "Stallion", "Rumpo", "RC Bandit",
	"Romero", "Packer", "Monster Truck", "Admiral", "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee",
	"Caddy", "Solair", "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic", "Sanchez", "Sparrow", "Patriot",
	"Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer",
	"Maverick", "News Chopper", "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick", "Boxville",
	"Benson", "Mesa", "RC Goblin", "Hotring Racer", "Hotring Racer", "Bloodring Banger", "Rancher", "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle",
	"Cropdust", "Stunt", "Tanker", "RoadTrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck",
	"Fortune", "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex",
	"Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada",
	"Yosemite", "Windsor", "Monster Truck", "Monster Truck", "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma",
	"Savanna", "Bandito", "Freight", "Trailer", "Kart", "Mower", "Duneride", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
	"Newsvan", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club", "Trailer", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car (LS)",
	"Police Car (SF)", "Police Car (LV)", "Police Ranger", "Picador", "S.W.A.T. Van", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer", "Luggage Trailer",
	"Stair Trailer", "Boxville", "Farm Plow", "Utility Trailer"
};

enum E_EASY_RADARS
{
	rID, // Radar ID
	rOwner[MAX_PLAYER_NAME],
	rTicket,
	rSpeedLimit,
	rOwnerID,
	rPlace[MAX_PLACE_NAME],
	Float: rPosX,
	Float: rPosY,
	Float: rPosZ,
	Float: rPosA,
	Text3D: label
};
static Radars[MAX_RADARS][E_EASY_RADARS];

static
	player_name[MAX_PLAYERS][MAX_PLAYER_NAME],
	current_radars = 0,
	player_radars[MAX_RADARS],
	selected_object[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
	GetPlayerName(playerid, player_name[playerid], MAX_PLAYER_NAME);
	SetPlayerTeam(playerid, TICKETS_SHOW_TEAM);
	#if defined EasyRadar_OnPlayerConnect
		return EasyRadar_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect EasyRadar_OnPlayerConnect
#if defined EasyRadar_OnPlayerConnect
	forward EasyRadar_OnPlayerConnect(playerid);
#endif

#if defined (RADARS_TYPE_BASIC)

	stock easy_strtok(const string[], &index)
	{
		new length = strlen(string);
		while ((index < length) && (string[index] <= ' '))
		{
			index++;
		}
		new offset = index;
		new result[20];
		while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
		{
			result[index - offset] = string[index];
			index++;
		}
		result[index - offset] = EOS;
		return result;
	}

	public OnPlayerCommandText(playerid, cmdtext[])
	{
		new index, temp[20], cmd[20], place[MAX_PLACE_NAME + 4], limit[20 + 1], radarID[20 + 1];
		cmd = easy_strtok(cmdtext, index);

		if(strcmp(cmd, "/sradar", true) == 0)
		{
			temp = strtok(cmdtext, index);
			
			if(!strlen(temp)) {
				return SendClientMessage(playerid, -1, "Укажите обязательные аргументы: /sradar [set/info/del/edit]");
			}

			if(strcmp(temp, "set", true) == 0) {
				limit = strtok(cmdtext, index);
				
				if(!strlen(limit) && (strlen(limit) < 1 || strlen(limit) > 3)) {
					return SendClientMessage(playerid, -1, "Укажите обязательные аргументы: /sradar set [limit] [название области]");
				}
				else {
					place = strtok(cmdtext, index);
					
					if(!strlen(place) && (strlen(place) < 3 || strlen(place) > 16)) {
						return SendClientMessage(playerid, -1, "Укажите обязательные аргументы: /sradar set [limit] [название области]");
					}
					
					new fmt_string[sizeof RADARS_CREATE_TEXT + (-4) + MAX_PLAYER_NAME + 16];
					format(fmt_string, sizeof fmt_string, RADARS_CREATE_TEXT, player_name[playerid], strval(limit), place);
					SendClientMessage(playerid, -1, fmt_string);
					
					new
						Float:playerX,
						Float:playerY,
						Float:playerZ,
						Float:playerAngle
					;
					GetPlayerFacingAngle(playerid, playerAngle);
					GetPlayerPos(playerid, playerX, playerY, playerZ);
					SetRadar(playerid, playerX, playerY, playerZ, playerAngle, strval(limit), place, player_name[playerid]);
				}
			}
			else if(strcmp(temp, "edit", true) == 0) {
				radarID = strtok(cmdtext, index);

				if(!strlen(radarID) && (strlen(radarID) < 1 || strval(radarID) > 3)) {
					return SendClientMessage(playerid, -1, "Укажите обязательный аргумент: /sradar edit [radarID]");
				}
				if(strlen(Radars[strval(radarID)][rOwner]) < 3) {
					return SendClientMessage(playerid, -1, "Радар не создан!");
				}
				if(!IsPlayerInRangeOfPoint(playerid, 5.0, Radars[strval(radarID)][rPosX], Radars[strval(radarID)][rPosY], Radars[strval(radarID)][rPosZ])) {
					return SendClientMessage(playerid, -1, "Вы должны находиться рядом с радаром!");
				}
				selected_object[playerid] = strval(radarID);
				EditObject(playerid, player_radars[strval(radarID)]); 
			}
			else if(strcmp(temp, "del", true) == 0) {
				OnPlayerReceivesTiket(playerid, 5555, 0);
				radarID = strtok(cmdtext, index);

				if(!strlen(radarID) && (strlen(radarID) < 1 || strval(radarID) > 3)) {
					return SendClientMessage(playerid, -1, "Укажите обязательный аргумент: /sradar del [radarID]");
				}
				if(strlen(Radars[strval(radarID)][rOwner]) < 3) {
					return SendClientMessage(playerid, -1, "Радар не создан!");
				}
				DeleteRadar(playerid, strval(radarID));
			}
		}
	
		#if defined EasyRadar_OnPlayerCommandText
			return EasyRadar_OnPlayerCommandText(playerid, cmdtext[]);
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnPlayerCommandText
		#undef OnPlayerCommandText
	#else
		#define _ALS_OnPlayerCommandText
	#endif

	#define OnPlayerCommandText EasyRadar_OnPlayerCommandText
	#if defined EasyRadar_OnPlayerCommandText
		forward EasyRadar_OnPlayerCommandText(playerid, cmdtext[]));
	#endif
#else

#endif

public OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{

    new
        Float: oldX,
        Float: oldY,
        Float: oldZ
	;

    GetObjectPos(objectid, oldX, oldY, oldZ);

	if(response == EDIT_RESPONSE_FINAL)
	{
		if(selected_object[playerid] >= 0)
		{
			if(IsPlayerInRangeOfPoint(playerid, 7.5, fX, fY, fZ)) {
				Radars[selected_object[playerid]][rPosX] = fX;
				Radars[selected_object[playerid]][rPosY] = fY;
				Radars[selected_object[playerid]][rPosZ] = fZ;
				Radars[selected_object[playerid]][rPosA] = fRotZ;
				
				
				SetObjectPos(player_radars[selected_object[playerid]], fX, fY, fZ);
				SetObjectRot(player_radars[selected_object[playerid]], fRotZ, fRotY, fRotZ);
				new
					fmt_string[sizeof RADARS_3DTEXT_LABEL + (-8) + 4 + MAX_PLAYER_NAME + 32];
				format(fmt_string, sizeof fmt_string, RADARS_3DTEXT_LABEL, Radars[selected_object[playerid]][rSpeedLimit], player_name[playerid], current_radars);
				
				Delete3DTextLabel(Radars[selected_object[playerid]][label]);
				Radars[selected_object[playerid]][label] = Create3DTextLabel(fmt_string, -1, fX, fY, fZ+1.5, RADARS_STREAM_DISTANCE, 0, 0);
				SendClientMessage(playerid, -1, "Вы успешно отредактировали объект!");
			}
			else
			{
				SetObjectPos(player_radars[selected_object[playerid]], oldX, oldY, oldZ);
				SendClientMessage(playerid, -1, "Вы не можете передвинуть так далеко объект!");
			}
		}
	}
	else if(response == EDIT_RESPONSE_CANCEL)
	{
		if(selected_object[playerid])
		{
			selected_object[playerid] = -1;
			SendClientMessage(playerid, -1, "Вы успешно отменили редактирование объекта!");
		}
	}

	return true;
}

forward bool:IsValidRadar(radarID);
public bool:IsValidRadar(radarID)
{
	if(player_radars[radarID] >= 0) return true;
	return false;
}

stock DeleteRadar(playerid, radarID)
{
	if(!IsValidRadar(radarID)) return false;
	
	new fmt_str[sizeof RADARS_DELETE_TEXT + (-4) + MAX_PLAYER_NAME + 24 + 1];
	format(fmt_str, sizeof fmt_str, RADARS_DELETE_TEXT, player_name[playerid], Radars[current_radars][rPlace]);
	
	for(new players, j = GetPlayerPoolSize(); players <= j; players++)
	{
		if(playerid == players)
			continue;
		SendClientMessage(players, -1, fmt_str);
	}
	DestroyObject(player_radars[radarID]);
	strins(Radars[current_radars][rOwner], "EOS", 0);
	strins(Radars[current_radars][rPlace], "EOS", 0);
	
	Radars[current_radars][rSpeedLimit] = 0;
	Radars[current_radars][rTicket] = 2000;
	Radars[current_radars][rOwnerID] = -1;
	
	Radars[current_radars][rPosX] = 0.0;
	Radars[current_radars][rPosY] = 0.0;
	Radars[current_radars][rPosZ] = 0.0;
	Radars[current_radars][rPosA] = 0.0;
	
	Delete3DTextLabel(Radars[radarID][label]);
	player_radars[radarID] = -1;
	current_radars--;

	
	return SendClientMessage(playerid, -1, "Вы успешно удалили объект");
}

stock SetRadar(playerid, Float:x, Float:y, Float:z, Float:angle, speedLimit, const radarPlace[], const radarOwner[])
{
	
	strins(Radars[current_radars][rOwner], radarOwner, 0);
	strins(Radars[current_radars][rPlace], radarPlace, 0);
	
	Radars[current_radars][rSpeedLimit] = speedLimit;
	Radars[current_radars][rTicket] = 2000;
	Radars[current_radars][rOwnerID] = playerid;
	
	Radars[current_radars][rPosX] = x;
	Radars[current_radars][rPosY] = y;
	Radars[current_radars][rPosZ] = z;
	Radars[current_radars][rPosA] = angle;
	
	player_radars[current_radars] = CreateObject(RADAR_OBJECT,x, y+1.5, z-1.5, 0.0, 0.0, angle);
	
	
	new
		fmt_string[sizeof RADARS_3DTEXT_LABEL + (-8) + 4 + MAX_PLAYER_NAME + 32];
	format(fmt_string, sizeof fmt_string, RADARS_3DTEXT_LABEL, speedLimit, player_name[playerid], current_radars);
	
	Radars[current_radars][label] = Create3DTextLabel(fmt_string, -1, x, y, z+1.5, RADARS_STREAM_DISTANCE, 0, 0);
	
	format(fmt_string, sizeof fmt_string, RADARS_CREATE_TEXT, player_name[playerid], speedLimit, radarPlace);
	
#if defined foreach
	foreach(new i : Player)
#else
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++) 
#endif
	{
		if(playerid == i)
			continue;
		SendClientMessage(i, -1, fmt_string);
	}
	current_radars++;
	return true;
}

forward OnPlayerReceivesTiket(playerid, speed, radarID);
public OnPlayerReceivesTiket(playerid, speed, radarID)
{
	#if !defined PAYMENT_TICKET_PRICE
		#define PAYMENT_TICKET_PRICE	2000
	#endif
	
	new
		string[ sizeof RADARS_TICKET_TEXT + (-2) + 24];
	if(Radars[radarID][rSpeedLimit] < speed) {
		format(string, sizeof string, RADARS_TICKET_TEXT, floatround( ( (speed-Radars[radarID][rSpeedLimit])/10) * PAYMENT_TICKET_PRICE) );
		SendClientMessage(playerid, -1, string);
		
		format(string, sizeof string, RADARS_INFO_TEXT, Radars[radarID][rPlace], Easy_CarNames[GetVehicleModel(GetPlayerVehicleID(playerid))-400], player_name[playerid]);
			
	#if defined foreach
		foreach(new i : Player)
	#else
		for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++) 
	#endif
		SendClientMessage(i, -1, string);
		
	}
	
	
	return true;
}