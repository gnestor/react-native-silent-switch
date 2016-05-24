import React from 'react'
import {NativeAppEventEmitter, NativeModules} from 'react-native'
const {SilentSwitch} = NativeModules

let eventListener = null

export default {
  addEventListener: callback => {
    SilentSwitch.subscribe()
    eventListener = NativeAppEventEmitter.addListener('SilentSwitch', ({status}) => {
      if (status === 'ON') return callback(true)
      if (status === 'OFF') return callback(false)
    })
  },
  removeEventListener: () => eventListener.remove()
}
