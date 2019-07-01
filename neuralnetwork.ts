//% weight=70 icon="\u30A2" color=#75CC05 block="NN"
namespace nn {


    //% blockId=nn_initfcnn
    //% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
    //% shim=nn::initfcnn
    export function initfcnn(inputs: number, hidden: number[], outputs: number): void {
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
    //% block="Predict|number[] %input|number[] %output"
    //% shim=nn::predict
    export function predict(input: number[], output: number[]): void {
    	basic.showString("sim-predict")
        return
    }

}
