// Data Structures

typedef enum Button {UP, DOWN, LEFT, RIGHT, TRIANGLE, X, SQUARE, CIRCLE, R1, R2, L1, L2} Button;

typedef struct {
	const char title[128];
	const char description[256];
	int combination[64];
	int numberOfButtons;
} Cheat;

// Cheats

static Cheat cheats[] = {
	{
		.title = "Invincibility",
		.description = "Only 5 minutes",
		.combination = {RIGHT, X, RIGHT, LEFT, RIGHT, R1, RIGHT, LEFT, X, TRIANGLE},
		.numberOfButtons = 10,
	},
	{
		.title = "Health & armor",
		.description = "",
		.combination = {CIRCLE, L1, TRIANGLE, R2, X, SQUARE, CIRCLE, RIGHT, SQUARE, L1, L1, L1},
		.numberOfButtons = 12,
		},
	{
		.title = "Weapons & ammo",
		.description = "",
		.combination = {TRIANGLE, R2, LEFT, L1, X, RIGHT, TRIANGLE, DOWN, SQUARE, L1, L1, L1},
		.numberOfButtons = 12,
		},
	{
		.title = "Lower wanted",
		.description = "Lower wanted level",
		.combination = {R1, R1, CIRCLE, R2, RIGHT, LEFT, RIGHT, LEFT, RIGHT, LEFT},
		.numberOfButtons = 10,
	},
	{
		.title = "Raise wanted level",
		.description = "",
		.combination = {R1, R1, CIRCLE, R2, LEFT, RIGHT, LEFT, RIGHT, LEFT, RIGHT},
		.numberOfButtons = 10,
	},
	{
		.title = "Recharge special ability",
		.description = "",
		.combination = {X, X, SQUARE, R1, L1, X, RIGHT, LEFT, X},
		.numberOfButtons = 9,
	},
	{
		.title = "Super jump",
		.description = "Hold square to jump",
		.combination = {LEFT, LEFT, TRIANGLE, TRIANGLE, RIGHT, RIGHT, LEFT, RIGHT, SQUARE, R1, R2},
		.numberOfButtons = 11,
	},
	{
		.title = "Faster run",
		.description = "",
		.combination = {TRIANGLE, LEFT, RIGHT, RIGHT, L2, L1, SQUARE},
		.numberOfButtons = 7,
	},
	{
		.title = "Faster swim",
		.description = "",
		.combination = {LEFT, LEFT, L1, RIGHT, RIGHT, R2, LEFT, L2, RIGHT},
		.numberOfButtons = 9,
	},
	{
		.title = "Flaming bullets",
		.description = "",
		.combination = {L1, R1, SQUARE, R1, LEFT, R2, R1, LEFT, SQUARE, RIGHT, L1, L1},
		.numberOfButtons = 12,
	},
	{
		.title = "Explosive bullets",
		.description = "",
		.combination = {RIGHT, SQUARE, X, LEFT, R1, R2, LEFT, RIGHT, RIGHT, L1, L1, L1},
		.numberOfButtons = 12,
	},
	{
		.title = "Ex. melee attack",
		.description = "Explosive melee attacks",
		.combination = {RIGHT, LEFT, X, TRIANGLE, R1, CIRCLE, CIRCLE, CIRCLE, L2},
		.numberOfButtons = 9,
	},
	{
		.title = "Slow-motion aim",
		.description = "",
		.combination = {SQUARE, L2, R1, TRIANGLE, LEFT, SQUARE, L2, RIGHT, X},
		.numberOfButtons = 9,
	},
	{
		.title = "Moon gravity",
		.description = "",
		.combination = {LEFT, LEFT, L1, R1, L1, RIGHT, LEFT, L1, LEFT},
		.numberOfButtons = 9,
	},
	{
		.title = "Slidey cars",
		.description = "",
		.combination = {TRIANGLE, R1, R1, LEFT, R1, L1, R2, L1},
		.numberOfButtons = 8,
	},
	{
		.title = "Spawn BMX bike",
		.description = "",
		.combination = {LEFT, LEFT, RIGHT, RIGHT, LEFT, RIGHT, SQUARE, CIRCLE, TRIANGLE, R1, R2},
		.numberOfButtons = 11,
	},
	{
		.title = "Spawn Buzzard",
		.description = "Small attack helicopter",
		.combination = {CIRCLE, CIRCLE, L1, CIRCLE, CIRCLE, CIRCLE, L1, L2, R1, TRIANGLE, CIRCLE, TRIANGLE},
		.numberOfButtons = 12,
	},
	{
		.title = "Spawn Caddy",
		.description = "Golf cart",
		.combination = {CIRCLE, L1, LEFT, R1, L2, X, R1, L1, CIRCLE, X},
		.numberOfButtons = 10,
	},
	{
		.title = "Spawn Comet",
		.description = "Sports car",
		.combination = {R1, CIRCLE, R2, RIGHT, L1, L2, X, X, SQUARE, R1},
		.numberOfButtons = 10,
	},
	{
		.title = "Spawn Duster",
		.description = "Crop duster plane",
		.combination = {RIGHT, LEFT, R1, R1, R1, LEFT, TRIANGLE, TRIANGLE, X, CIRCLE, L1, L1},
		.numberOfButtons = 12,
	},
	{
		.title = "Spawn Limo",
		.description = "Limousine",
		.combination = {R2, RIGHT, L2, LEFT, LEFT, R1, L1, CIRCLE, RIGHT},
		.numberOfButtons = 9,
	},
	{
		.title = "Spawn parachute",
		.description = "",
		.combination = {LEFT, RIGHT, L1, L2, R1, R2, R2, LEFT, LEFT, RIGHT, L1},
		.numberOfButtons = 11,
	},
	{
		.title = "Spawn PCJ-600",
		.description = "PCJ-600 motorcycle",
		.combination = {R1, RIGHT, LEFT, RIGHT, R2, LEFT, RIGHT, SQUARE, RIGHT, L2, L1, L1},
		.numberOfButtons = 12,
	},
	{
		.title = "Spawn Rapid GT",
		.description = "Sports car",
		.combination = {R2, L1, CIRCLE, RIGHT, L1, R1, RIGHT, LEFT, CIRCLE, R2},
		.numberOfButtons = 10,
	},
	{
		.title = "Spawn Sanchez",
		.description = "Dual-sport dirt bike",
		.combination = {CIRCLE, X, L1, CIRCLE, CIRCLE, L1, CIRCLE, R1, R2, L2, L1, L1},
		.numberOfButtons = 12,
	},
	{
		.title = "Spawn Stunt Plane",
		.description = "Fixed-wing stunt plane",
		.combination = {CIRCLE, RIGHT, L1, L2, LEFT, R1, L1, L1, LEFT, LEFT, X, TRIANGLE},
		.numberOfButtons = 12,
	},
	{
		.title = "Spawn Trashmaster",
		.description = "Garbage truck",
		.combination = {CIRCLE, R1, CIRCLE, R1, LEFT, LEFT, R1, L1, CIRCLE, RIGHT},
		.numberOfButtons = 10,
	},
	{
		.title = "Skydive free fall",
		.description = "Can't use parachute",
		.combination = {L1, L2, R1, R2, LEFT, RIGHT, LEFT, RIGHT, L1, L2, R1, R2, LEFT, RIGHT, LEFT, RIGHT},
		.numberOfButtons = 16,
	},
	{
		.title = "Drunk mode",
		.description = "",
		.combination = {TRIANGLE, RIGHT, RIGHT, LEFT, RIGHT, SQUARE, CIRCLE, LEFT},
		.numberOfButtons = 8,
	},
	{
		.title = "Slow motion",
		.description = "5º time disables it",
		.combination = {TRIANGLE, LEFT, RIGHT, RIGHT, SQUARE, R2, R1},
		.numberOfButtons = 7,
	},
	{
		.title = "Change weather",
		.description = "Rotates to a different weather",
		.combination = {R2, X, L1, L1, L2, L2, L2, SQUARE},
		.numberOfButtons = 8,
	},
};