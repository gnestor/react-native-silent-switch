# React Native Silent Switch

Detect the iOS silent switch using React Native

## Install

### Using [rnpm](https://github.com/rnpm/rnpm)

* Install: `rnpm install react-native-silent-switch`
* Add `mute.aiff` from the library to your project bundle
  * Project Navigator > [YOUR PROJECT NAME] > Build Phases > Copy Bundle Resources
* Verify that `$(SRCROOT)/../../node_modules/react-native/React` is in the library's header search paths for both Debug and Release schemes
    * Project Navigator > RCTSilentSwitch.xcodeproj > Build Settings > Header Search Paths > Debug AND Release

### Manually

* Install: `npm install react-native-silent-switch --save`
* Link library in Xcode: See [React Native guide](https://facebook.github.io/react-native/docs/linking-libraries-ios.html)
* Add `mute.aiff` from the library to your project bundle
  * Project Navigator > [YOUR PROJECT NAME] > Build Phases > Copy Bundle Resources
* Verify that `$(SRCROOT)/../../node_modules/react-native/React` is in the library's header search paths for both Debug and Release schemes
  * Project Navigator > RCTSilentSwitch.xcodeproj > Build Settings > Header Search Paths > Debug AND Release

## Usage

```js
import SilentSwitch from 'react-native-silent-switch'
```

```js
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

## Usage with [react-native-statusbar-alert](https://github.com/gnestor/react-native-statusbar-alert)

```js
import SilentSwitch from 'react-native-silent-switch'
import StatusBarAlert from 'react-native-statusbar-alert'
```

```js
componentDidMount() {
  SilentSwitch.addEventListener(silent => {
    if (silent) {
      this.setState({
        alerts: [{
          message: 'Silent Switch ON',
          onPress: () => this.navigator.push({id: 'SilentAlert'})
        }, ...this.state.alerts]
      })
    } else {
      this.setState({
        alerts: this.state.alerts.filter(alert => alert.message !== 'Silent Switch ON')
      })
    }
  })
}

componentWillUnmount() {
  SilentSwitch.removeEventListener()
}

render() {
  return (
    <View style={styles.container}>
      <StatusBarAlert
        visible={this.state.alerts.length > 0}
        {...this.state.alerts[0]}
      />
      <Navigator
        initialRoute={initialRoute}
        renderScene={this.renderScene}
        navigationBar={
          <Navigator.NavigationBar
            routeMapper={routeMapper}
            style={{top: -20}}
          />
        }
      />
    </View>
  )
}
```
