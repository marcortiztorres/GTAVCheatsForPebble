#include <pebble.h>
#include <pebble_fonts.h>
#include "cheats.c"

#define NUMBER_OF_CHEATS (int)ARRAY_LENGTH(cheats)
	
// Cheat window declaration

Window * cheatWindow;
TextLayer * buttonText;

AppTimer * timer;
int currentCheatIndex;
int currentButtonIndex;
int timeIntervalBetweenButtons = 900;
GColor currentBackgroundColor = GColorWhite;

void initCheatWindow();
void clickConfigProvider(Window * cheatWindow);
void backButtonClickedHandler(ClickRecognizerRef clickRecognizerRef, void * context);
void dismissCheatWindow();
void showCheatWindowWithIndex(int index);
void showNextButtonOrExit();

// Cheat window implementation

void initCheatWindow() {
	cheatWindow = window_create();
	window_set_click_config_provider(cheatWindow, (ClickConfigProvider)clickConfigProvider);
	
	buttonText = text_layer_create(layer_get_frame(window_get_root_layer(cheatWindow)));
}

void clickConfigProvider(Window * cheatWindow) {
	window_single_click_subscribe(BUTTON_ID_BACK, backButtonClickedHandler);
}

void backButtonClickedHandler(ClickRecognizerRef clickRecognizerRef, void * context) {
	dismissCheatWindow();
}

void dismissCheatWindow() {
	currentCheatIndex = 0;
	currentButtonIndex = 0;
	app_timer_cancel(timer);
	currentBackgroundColor = GColorWhite;
	window_stack_remove(cheatWindow, true);
}

void showCheatWindowWithIndex(int index) {
	currentCheatIndex = index;
	
	window_stack_push(cheatWindow, true);
	
	text_layer_set_text(buttonText, cheats[index].title);
	text_layer_set_font(buttonText, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
	text_layer_set_overflow_mode(buttonText, GTextOverflowModeTrailingEllipsis);
	text_layer_set_text_alignment(buttonText, GTextAlignmentCenter);
	text_layer_set_background_color(buttonText, currentBackgroundColor);
	text_layer_set_text_color(buttonText, GColorBlack);
	layer_add_child(window_get_root_layer(cheatWindow), text_layer_get_layer(buttonText));
	
	timer = app_timer_register(1250, showNextButtonOrExit, NULL);
}

void showNextButtonOrExit() {
	if (currentButtonIndex < cheats[currentCheatIndex].numberOfButtons) {
		Button currentButton = cheats[currentCheatIndex].combination[currentButtonIndex];
	
		switch (currentButton) {
			case UP:
			text_layer_set_text(buttonText, "UP");
			break;
			case DOWN:
			text_layer_set_text(buttonText, "DOWN");
			break;
			case LEFT:
			text_layer_set_text(buttonText, "LEFT");
			break;
			case RIGHT:
			text_layer_set_text(buttonText, "RIGHT");
			break;
			case TRIANGLE:
			text_layer_set_text(buttonText, "TRIANGLE");
			break;
			case X:
			text_layer_set_text(buttonText, "X");
			break;
			case SQUARE:
			text_layer_set_text(buttonText, "SQUARE");
			break;
			case CIRCLE:
			text_layer_set_text(buttonText, "CIRCLE");
			break;
			case R1:
			text_layer_set_text(buttonText, "R1");
			break;
			case R2:
			text_layer_set_text(buttonText, "R2");
			break;
			case L1:
			text_layer_set_text(buttonText, "L1");
			break;
			case L2:
			text_layer_set_text(buttonText, "L2");
			break;
		}
		
		text_layer_set_text_color(buttonText, currentBackgroundColor == GColorBlack ? GColorBlack : GColorWhite);
		text_layer_set_background_color(buttonText, currentBackgroundColor == GColorBlack ? GColorWhite : GColorBlack);
		currentBackgroundColor = currentBackgroundColor == GColorBlack ? GColorWhite : GColorBlack;
		
		currentButtonIndex++;
		timer = app_timer_register(timeIntervalBetweenButtons, showNextButtonOrExit, NULL);
	} else {
		psleep(timeIntervalBetweenButtons);
		dismissCheatWindow();
	}
}

// Root window declaration
	
Window * rootWindow;

SimpleMenuLayer * cheatMenu;
SimpleMenuSection cheatSection[1];
SimpleMenuItem cheatItems[NUMBER_OF_CHEATS];

void initRootWindow();
void initCheatMenu();
void cheatSelectionCallback(int index, void * context);

// Root window implementation

void initAndShowRootWindow() {
	rootWindow = window_create();
	initCheatMenu();
	
	window_stack_push(rootWindow, true);
}

void initCheatMenu() {
	for (int i = 0; i < NUMBER_OF_CHEATS; i++) {
		const char * cheatTitle = cheats[i].title;
		const char * cheatDescription = cheats[i].description;
		cheatItems[i] = (SimpleMenuItem){.title = cheatTitle, .subtitle = strcmp(cheatDescription, "") == 0 ? NULL : cheatDescription, .icon = NULL, .callback = cheatSelectionCallback};			
	}

	cheatSection[0] = (SimpleMenuSection){.items = cheatItems, .num_items = NUMBER_OF_CHEATS, .title = "GTA V Cheats"};
	
	Layer * rootWindowLayer = window_get_root_layer(rootWindow);
	GRect rootWindowFrame = layer_get_frame(rootWindowLayer);
	cheatMenu = simple_menu_layer_create(rootWindowFrame, rootWindow, cheatSection, 1, NULL);
	layer_add_child(rootWindowLayer, simple_menu_layer_get_layer(cheatMenu));
}

void cheatSelectionCallback(int index, void * context) {
	showCheatWindowWithIndex(index);
}

// Main methods

void init() {
	initAndShowRootWindow();
	initCheatWindow();
}

void deinit() {
	window_destroy(cheatWindow);
	text_layer_destroy(buttonText);
	
	window_destroy(rootWindow);
	simple_menu_layer_destroy(cheatMenu);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}