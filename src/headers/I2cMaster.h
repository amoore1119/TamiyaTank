
void sercomI2cWrite (Sercom *sercom, const uint8_t addr, const uint8_t *data, const uint8_t size);
void sercomI2cRead (Sercom *sercom, const uint8_t addr, const uint8_t reg, uint8_t *buf, uint8_t size);
void sercomI2cHandler (Sercom *sercom);
void sercomI2cReset (Sercom *sercom);
void initI2cMaster (Sercom *sercom);
