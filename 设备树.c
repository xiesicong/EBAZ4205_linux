/include/ "system-conf.dtsi"

#define GPIO_ACTIVE_HIGH 0
#define GPIO_ACTIVE_LOW 1

/ {
    model = "E9 Board";
    compatible = "xiesicong,zynq-7000","xlnx,zynq-7000";


    leds {
        compatible = "gpio-leds";
        status = "okay";
        
        gpio-led1 {
        label = "pl_led1";
        gpios = <&gpio0 54 GPIO_ACTIVE_HIGH>;
        linux,default-trigger = " timer";
        };

        gpio-led2 {
        label = "pl_led2";
        gpios = <&gpio0 55 GPIO_ACTIVE_HIGH>;
        linux,default-trigger = " heartbeat";
        };

        gpio-led3 {
        label = "pl_led3";
        gpios = <&gpio0 56 GPIO_ACTIVE_HIGH>;
        default-state = "off";
        };

        gpio-led4 {
        label = "pl_led4";
        gpios = <&gpio0 57 GPIO_ACTIVE_HIGH>;
        default-state = "on";
        };
    };
};


&gem0 {
  status = "okay";
  local-mac-address = [00 0a 35 00 01 22];
  phy-handle =<&phy0>;
  phy-mode = "mii";
  mdio {
       phy0:phy@0 {
         device_type = "ethernet-phy";
         reg = <0>;    
        };
      };
};

&nand0 {
	arm,nand-cycle-t0 = <0x4>;
	arm,nand-cycle-t1 = <0x4>;
	arm,nand-cycle-t2 = <0x2>;
	arm,nand-cycle-t3 = <0x2>;
	arm,nand-cycle-t4 = <0x2>;
	arm,nand-cycle-t5 = <0x2>;
	arm,nand-cycle-t6 = <0x3>;
	status = "okay";
};

