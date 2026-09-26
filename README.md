# Edd's QMK Userspace

This contains keymaps for the following boards. Images thanks to [@whitehatenetizen](https://whitehatnetizen.github.io/keymap-imgen/).

For split boards, all keys acting as control as modifier use left control. The shortcuts on the function layer use right control. Karabiner is used on macos to remap right control to right command (I could also do this with a QMK magic key). In this way I can use the same keys for copy/paste etc, but still deliberately use control and command in, e.g. gnome (which uses gui as much as alt, especially with paperwm) and emacs. Emacs also does a lot of shift+num shortcuts, which are comfortable with the symbol layer. The "drum roll" shortcuts of left/right and right/left rolls on the outer thumb key do command/gui+enter and command/gui+tab. The former does form submission, and I recommend you add it in your editor for save/submit/etc.

There are a bunch of useful PC media keys that macos chooses not to support but can be wrangled with [karabiner](https://github.com/eddsteel/nix-configuration/blob/main/modules/home/layers/macos/files/karabiner.json#L278-L501) until Apple get their act together.

Otherwise I took a lot of ideas from https://onedeadkey.github.io/selenium/, mixing their regular and vim variants. I'm married to my symbol layer, though. I added macos punctuation shortcuts to the spare keys since gnome has a better alternative (the compose key, I use application).

## Corne v4.1

![eddsteel keymap for corne v4.1](maps/crkbd-rev4_1-standard-eddsteel.png)

## ZSA Moonlander rev A

![eddsteel keymap for moonlander](maps/zsa-moonlander-eddsteel.png)


## KBDFans KBD75 rev 1

![eddsteel keymap for KBD75](maps/kbdfans-kbd75-rev1-eddsteel.png)
