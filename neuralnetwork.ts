//% weight=70 icon="\u30A2" color=#75CC05 block="NN"
namespace nn {


    //% blockId=nn_initFCNN
    //% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
    //% shim=nn::initFCNN
    export function initFCNN(inputs: number, hidden: number[], outputs: number): void {
    	basic.showString("sim:init")
    }

    //% blockId=nn_train
    //% block="Train|number[] %input|number[] %expected_output"
    //% shim=nn::train
    export function train(input: number[], expected_output: number[]): number {
    	basic.showString("sim-train")
        return 1
    }


    //% blockId=nn_predict
    //% block="Predict|number[] %input"
    //% shim=nn::predict
    export function predict(input: number[]): number[] {
    	basic.showString("sim-predict")
        return input
    }

}
