#include "InputReaderFactory.h"
#include "../Reader/KeyboardReader.h"
#include "ControlSchemeProvider.h"

Reader *InputReaderFactory::create() {
    ControlSchemeProvider schemeProvider{"E:/Game_ver2.0/Facade/Logic/Data/Settings"};
    KeyboardReader *keyboardReader = new KeyboardReader();
    keyboardReader->setCommands(schemeProvider.setSettings());
    sfmlHandler->addSubscriber(keyboardReader);
    return keyboardReader;
}


InputReaderFactory::InputReaderFactory(SFMLHandler *handler) {
    sfmlHandler = handler;
}
