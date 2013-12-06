/*
 
 Copyright (c) 2013 BlueShield
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
*/

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef void (^BSSuccessBlock)(id response, NSError *error);

@interface BlueShield : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

@property (strong, nonatomic) NSMutableArray *peripherals;
@property (strong, nonatomic) CBCentralManager *cm;
@property (strong, nonatomic) CBPeripheral *activePeripheral;

- (void)writeValue:(CBUUID *)serviceUUID characteristicUUID:(CBUUID *)characteristicUUID  p:(CBPeripheral *)p data:(NSData *)data;
- (void)readValue:(CBUUID *)serviceUUID characteristicUUID:(CBUUID *)characteristicUUID  p:(CBPeripheral *)p;
- (void)notification:(CBUUID *)serviceUUID characteristicUUID:(CBUUID *)characteristicUUID  p:(CBPeripheral *)p on:(BOOL)on;

- (UInt16)swap:(UInt16)s;
- (int)controlSetup;
- (int)findBLEPeripherals:(int)timeout;
- (const char *)centralManagerStateToString:(int)state;
- (void)scanTimer:(NSTimer *)timer;
- (void)printKnownPeripherals;
- (void)printPeripheralInfo:(CBPeripheral*)peripheral;
- (void)connectPeripheral:(CBPeripheral *)peripheral;

- (CBService *)findServiceFromUUID:(CBUUID *)UUID p:(CBPeripheral *)p;
- (CBCharacteristic *)findCharacteristicFromUUID:(CBUUID *)UUID service:(CBService*)service;
- (const char *)UUIDToString:(CFUUIDRef)UUID;
- (const char *)CBUUIDToString:(CBUUID *)UUID;
- (int)compareCBUUID:(CBUUID *)UUID1 UUID2:(CBUUID *)UUID2;
- (int)compareCBUUIDToInt:(CBUUID *)UUID1 UUID2:(UInt16)UUID2;
- (UInt16)CBUUIDToInt:(CBUUID *)UUID;
- (int)UUIDSAreEqual:(CFUUIDRef)u1 u2:(CFUUIDRef)u2;

- (void)didUpdateValueBlock:(BSSuccessBlock)block;
- (void)didPowerOnBlock:(BSSuccessBlock)block;
- (void)didDiscoverCharacteristicsBlock:(BSSuccessBlock)block;

@end
