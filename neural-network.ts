//% weight=70 icon="\u30A2" color=#EC7505 block="NN"
namespace nn {

    //% blockId=nn_test
    //% block="Test"
    //% shim=nn::test
    export function test(): void {
    	basic.showString("sim-NN-test")
        return
    }

    /**
     * prints a string
     * @param text text to display, eg: "Hi, CPP!"
     */
     //% weight=92 blockGap=8
     //% block="Show|string %text" 
     //% blockId=nn_show
     //% shim=nn::show
     export function show(text: string): void {
        console.log("sim:" + text)
    	basic.showString("sim:" + text)
        return
	}

    //% blockId=nn_gettime
    //% block="Current Time" 
    //% shim=nn::gettime
	export function gettime(): string {
		return "sim:12:00:00"
	}

}
