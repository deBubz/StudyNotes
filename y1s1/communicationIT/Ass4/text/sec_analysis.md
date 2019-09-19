# Security Analysis: CONSUMER IOT DEVICES CONTINUE TO THREATEN THE INTERNET WITH DDOS ATTACKS

## TOLAGA research 2017

## Abs

DDOS attacks from infected IoT device, which is lack of any basic security features.
Some manufacturers are held accountable.
__Internet Service Providers(ISP)__ can see the trafic but its too complex and expensive to response.
Companies are vulnerable from both internal and external threats.

To identify and mitigate threats, need:

- Network monitoring
- Heuristic(self discovering) and machine lerning techniques.

---

## Background

- People are eager to adopt IoT
- Readily availible in Electronic Stores, easy to setup Plug/Play
- Most devices are shipped with remote-acess ability, containing the default/ unchanged admin security credentials.
- Easy to take over the adminstartive functions of the device.
- Even if the device is accessed, it can be protected by having:
  - Firmware/ Operational software is digitally signed to restrict commands/controll from attacher
  - Secret Password Keys are stored in protected memory, and administrative access is restricted.
  - Serverside security mechanism to restrict MITM attacks.

- These basic features are commonly excluded.
- Manufacturer's incentive is __"to rapidly produce low cost devices, with security largelybeing an after-thought"__

---

## Security Risk

- __Attacks__ Ransomware, reconnaissance and eves-dropping, weponizatrion for DDOS attacks.
- __DDOS__: flood and deny services.
  - Since Domain Name System(DNS) responsible to translate URL into IP
  - __DYN__ Oracle owned DNS attacked by ddos in 21 OCT 2016. Disabled Github, Twitter, reddit, AirBnb
  - Attacked by Mirai botnet, which uses insecure IoT devices.
- __Mirai__ was not the first IoT DDOS. Was made OpenSourced and encorporate in other Malicous Software:
  - Mirai can be clense by factory rebooting. A variant can keep the device infected.
  - Mirai Scans for devices using telnet port 23, Some manufacturers changed the port, but a variant can scan for the changed port.
  - The list for devices that uses default credentials is increased.
  - Some variant is using an alternate attack vector(path/way).

---

## Mitigation and protection strategies

- This could be just the "tip-of-the-iceberg" on IoT DDOs attacks.
- Not realistic to be 100% protected from DDOS __BUT__ most vulnerabilities are from basic design flaw.
- __*unprotected credentials__ and __remote-acess fuctionalities__
- Some manufacturer had pay more attention to this BUT __"more focus is needed in making security inherent to device designs."__

### Who is responsible

- There are efforts to make manufacturers held __accountable__ for producing insecure devices.
- This make manufacturers open for lawsuits and force product recall.
- Oct 2016, XiongMai product recall due to their devices were used for DDOS attacks, Several millions were infected.
- January 2017, US Federal Trade Commission(FTC) had legal actioned agaisnt D-link for not having adequate security on its routers and security-cameras.
- Could set precedent.
- the EU mooted?? a certification scheme to identify and lable insecure devices. This will be hard since vulnerabilities and attacks vectors are continuosly changing.
- The devices deemed secure could be targets for attackers.

### Internet Service Provider

- ISP plays a big role id protecting the Internet, since they can monitor traffic.
- BUT quarantining IP and devices is very complex and expensive.
- Quarantining can also create other customer service challanges and have negative impact on the ISP brand and reputation.

- Beside from ISP, Enterprises are encourange to monitor their own traffic. To recognize potential internal and external attacks to protect themselves against it.
- Also reccomended to set strick policies on how IoT devices are delt. Keeping them always updated.
- Heuristic and machine learining are solutions are increasingly playing an important role in security.

__NOTE__: great table.
