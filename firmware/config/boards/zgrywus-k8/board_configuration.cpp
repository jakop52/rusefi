#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::G0;
}

static void setEtbConfig() {
	engineConfiguration->etbIo[0].controlPin = Gpio::E7;
	engineConfiguration->etbIo[0].directionPin1 = Gpio::E9;
	engineConfiguration->etbIo[0].disablePin = Gpio::E8;
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;
}

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.516f;
	engineConfiguration->vbattAdcChannel = EFI_ADC_11;
}

static void K8_BoardConfigOverrides() {
	setupVbatt();
	setEtbConfig();

	engineConfiguration->clt.config.bias_resistor = 2200;
	engineConfiguration->iat.config.bias_resistor = 2200;

	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->canTxPin = Gpio::D1;

	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->spi1mosiPin = Gpio::B5;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1sckPin = Gpio::B3;

	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->spi3mosiPin = Gpio::C12;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3sckPin = Gpio::C10;

	engineConfiguration->max31855spiDevice = SPI_DEVICE_1;
	engineConfiguration->max31855_cs[0] = Gpio::B9;

	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->sdCardCsPin = Gpio::D2;
}

static void K8_DefaultConfiguration() {
	engineConfiguration->adcVcc = 3.3f;
	engineConfiguration->vbattDividerCoeff = (3.277 + 0.51) / 0.51;
}

void setup_custom_board_overrides() {
	custom_board_ConfigOverrides = K8_BoardConfigOverrides;
	custom_board_DefaultConfiguration = K8_DefaultConfiguration;
}
