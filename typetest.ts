//% weight=70 icon="\u30A2" color=#EC7505 block="TT"
namespace tt {

    //% blockId=tt_test
    //% block="Test"
    //% shim=tt::test
    export function test(): void {
    	basic.showString("sim-tt-test")
        return
    }

    /**
     * prints a string
     * @param text text to display, eg: "Hi, CPP!"
     */
     //% weight=92 blockGap=8
     //% block="Show|string %text" 
     //% blockId=tt_show
     //% shim=tt::show
     export function show(text: string): void {
        console.log("sim:" + text)
    	basic.showString("sim:" + text)
        return
	}

    /**
     * log a number.
     * @param num number to display, eg: 1.5
     */
     //% weight=92 blockGap=8
     //% block="Log Number|number %num" 
     //% blockId=tt_lognum
     //% shim=tt::lognum
     export function lognum(num: number): void {
        console.log("sim:")
        return
	}


    //% blockId=tt_gettime
    //% block="Current Time" 
    //% shim=tt::gettime
	export function gettime(): string {
		return "sim:12:00:00"
	}

	//% blockId=tt_sumvec
	//% block="Sum Vec|number[] %vec"
	//% shim=tt::sumvec
	export function sumvec(vec: number[]): number {
        console.log("sim:" + vec[0])
        return vec[0]
	}
	
	//% blockId=tt_addvec
	//% block="Add Vec|number[] %vec1|number[] %vec2"
	//% shim=tt::addvec
	export function addvec(vec1: number[], vec2: number[]): number[] {
        console.log("sim:" + (vec1[0]+vec2[0]))
        return vec1
	}
	

}
