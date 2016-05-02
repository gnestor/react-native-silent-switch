# React Native Silent Switch

Detect the iOS silent switch using React Native

## Install

### Using [rnpm](https://github.com/rnpm/rnpm)

* Install: `rnpm install react-native-silent-switch`
* Add AudioToolbox.framework and Foundation.framework to your project
  * Project Navigator > [YOUR PROJECT NAME] > Build Phases > Link Binary with Libraries

### Manually

* Install: `npm install react-native-silent-switch`
* Link library in Xcode: See [React Native guide](https://facebook.github.io/react-native/docs/linking-libraries-ios.html)
* Add AudioToolbox.framework and Foundation.framework to your project
  * Project Navigator > [YOUR PROJECT NAME] > Build Phases > Link Binary with Libraries
* Add `mute.caf` from the library to your project bundle
  * Project Navigator > [YOUR PROJECT NAME] > Build Phases > Copy Bundle Resources

## Usage

```js
import SilentSwitch from 'react-native-silent-switch'

componentDidMount() {
  // Listen for silent switch toggle events
  SilentSwitch.addEventListener(silent => {
    // When switched to silent, the callback will return true. When switched from silent, it will return false.
    if (silent) this.navigator.push({id: 'SilentAlert'})
  })
}

componentWillUnmount() {
 SilentSwitch.removeEventListener()
}
```
