from decimal import Decimal

from currency.models import Currency
from django.core.exceptions import ObjectDoesNotExist


class CurrencyService:
    def create_currency(
        self, name: str, acronym: str, symbol: str, usd_rate: float
    ) -> Currency:
        """Create a new currency with validation"""
        if len(acronym) != 3:
            raise ValueError("Acronym must be 3 characters")

        if usd_rate <= 0:
            raise ValueError("Exchange rate must be positive")

        currency = Currency(
            name=name, acronym=acronym.upper(), usd_rate=usd_rate, symbol=symbol
        )
        currency.save()

        return currency

    def get_all_currencies(self) -> list[Currency]:
        """Return all currencies ordered by acronym"""
        return list(Currency.objects.all().order_by("acronym"))

    def convert(self, value: float, source: str, dest: str) -> float:
        """Return the converted value"""
        try:
            currency_from = Currency.objects.get(acronym=source)
            currency_to = Currency.objects.get(acronym=dest)
        except ObjectDoesNotExist:
            raise ValueError("Currency not found")

        return Decimal(str(value)) * currency_to.usd_rate / currency_from.usd_rate
