spin_lock_irqsave(&as->lock, flags);
if (!usbin_retire_desc(u, urb) &&
    u->flags & FLG_RUNNING &&
    !usbin_prepare_desc(u, urb) &&
-    (suret = usb_submit_urb(urb)) == 0) {
+    (suret = usb_submit_urb(urb,GFP_ATOMIC)) == 0) {
  u->flags |= mask;
} else {
  u->flags &= ~(mask | FLG_RUNNING);
  wake_up(&u->dma.wait);
  printk(KERN_DEBUG "...", suret);
}
spin_unlock_irqrestore(&as->lock, flags);
